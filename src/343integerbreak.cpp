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
    int integerBreak(int n)
    {
        int maxNum = INT32_MIN;
        vector<int> dp(n + 1);
        for (int i = 2; i <= n; i++)
        {
            if (n / i * i == n)
            {
                dp[i] = 1;
                for (int j = 0; j < i; j++)
                {
                    dp[i] *= n / i;
                }
            }
            else
            {
                int diff = n - n / i * i;
                dp[i] = 1;
                for (int j = 0; j < i; j++)
                {
                    if (diff > 0)
                    {
                        dp[i] *= (n / i + 1);
                        diff--;
                    }
                    else
                    {
                        dp[i] *= n / i;
                    }
                }
            }
            if (dp[i] > maxNum)
            {
                maxNum = dp[i];
            }
        }
        return maxNum;
    }
};
int main()
{
    Solution sol;
    cout << sol.integerBreak(8) << endl;
    return 0;
}