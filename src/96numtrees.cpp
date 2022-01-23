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
    int numTrees(int n)
    {
        vector<int> dp(n + 1, 0);
        if (n <= 2)
        {
            return n;
        }
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            int half = i / 2;
            dp[i] = 0;
            if (i % 2 == 0)
            {
                for (int j = i - 1; j >= i - half; j--)
                {
                    dp[i] += dp[j] * dp[i - j - 1];
                }
                dp[i] *= 2;
            }
            else
            {
                for (int j = i - 1; j >= i - half; j--)
                {
                    dp[i] += dp[j] * dp[i - j - 1];
                }
                dp[i] *= 2;
                dp[i] += dp[(i - 1) / 2] * dp[(i - 1) / 2];           
            }
        }
        return dp[n];
    }
    int numTrees1(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};
int main()
{
    Solution sol;
    cout << sol.numTrees1(3) << endl;
    return 0;
}