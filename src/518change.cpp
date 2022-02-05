#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <stdlib.h>
#include <math.h>
#include <sstream>
#include <list>
using namespace std;

class Solution
{
public:
    int change(int amount, vector<int>& coins)
    {
        if (amount == 0)
        {
            return 1;
        }
        vector<int> dp(amount + 1, 0);
        int count = 0;
        vector<int> cts(amount + 1, 0);
        for (int i = 0; i < coins.size(); i++)
        {
            if (coins[i] <= amount)
            {
                int val = coins[i];
                cts[val] += 1;
            }
            for (int j = coins[i]; j <= amount; j++)
            {
                if (dp[j - coins[i]] + coins[i] == j)
                {
                    cts[j] += cts[j - coins[i]];
                }
                dp[j] = max(dp[j], dp[j - coins[i]] + coins[i]);
            }
        }
        if (dp[amount] != amount)
        {
            return 0;
        }
        return cts[amount];
    }
    int change1(int amount, vector<int>& coins)
    {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = coins[i]; j <= amount; j++)
            {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};
int main()
{
    Solution sol;
    vector<int> weight{1, 2, 5};
    cout << sol.change1(5, weight) << endl;
    return 0;
}


//      0    1    2    3    4     5
// 1    1    1    1    1    1     1
// 2              2    2    3     3
// 5                              4