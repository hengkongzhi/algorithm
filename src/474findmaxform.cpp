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
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        vector<int> value(strs.size(), 1);
        vector<int> weight0(strs.size(), 0);
        vector<int> weight1(strs.size(), 0);
        for (int i = 0; i < strs.size(); i++)
        {
            for (int j = 0; j < strs[i].size(); j++)
            {
                if (strs[i][j] == '0')
                {
                    weight0[i] = weight0[i] + 1;
                }
                else
                {
                    weight1[i] = weight1[i] + 1;
                }
            }
        }
        vector<int> dp(m + 1, 0);
        for (int i = 0; i < weight0.size(); i++)
        {
            for (int j = m; j >= weight0[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - weight0[i]] + value[i]);
            }
        }
        vector<int> dp1(n + 1, 0);
        for (int i = 0; i < weight1.size(); i++)
        {
            for (int j = n; j >= weight1[i]; j--)
            {
                dp1[j] = max(dp1[j], dp1[j - weight1[i]] + value[i]);
            }
        }
        return min(dp[m], dp1[n]);
    }
    int findMaxForm1(vector<string>& strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < strs.size(); i++)
        {
            int zeroNums = 0;
            int oneNums = 0;
            for (int j = 0; j < strs[i].size(); j++)
            {
                if (strs[i][j] == '0')
                {
                    zeroNums++;
                }
                else
                {
                    oneNums++;
                }
            }
            for (int k = m; k >= zeroNums; k--)
            {
                for (int l = n; l >= oneNums; l--)
                {
                    dp[k][l] = max(dp[k][l], dp[k - zeroNums][l - oneNums] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
int main()
{
    Solution sol;
    vector<string> weight{"10","0001","111001","1","0"};
    cout << sol.findMaxForm1(weight, 4, 3) << endl;
    return 0;
}