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
    vector<vector<int>> packege01(vector<int>& weight, vector<int>& value, int sumWeight)
    {
        vector<vector<int>> dp(weight.size(), vector<int>(sumWeight + 1, 0));
        for (int i = 0; i < weight.size(); i++)
        {
            dp[i][0] = 0;
        }
        for (int j = 0; j < sumWeight + 1; j++)
        {
            if (j >= weight[0])
            {
                dp[0][j] = value[0];
            }
        }
        for (int i = 1; i < weight.size(); i++)
        {
            for (int j = 1; j < sumWeight + 1; j++)
            {
                if (j < weight[i])
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
                }
            }
        }
        return dp;
        
    }
    void vecPrint(const vector<vector<int>>& dp)
    {
        for (auto vec : dp)
        {
            for (auto num : vec)
            {
                cout << num << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    Solution sol;
    vector<int> weight{1, 3, 4};
    vector<int> value{15, 20, 30};
    sol.vecPrint(sol.packege01(weight, value, 4));
    return 0;
}