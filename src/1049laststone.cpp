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
    int lastStoneWeightII(vector<int>& stones)
    {
        int sum = 0;
        for (int i = 0; i < stones.size(); i++)
        {
            sum += stones[i];
        }
        int half = sum / 2;
        vector<int> dp(half + 1, 0);
        for (int i = 0; i < stones.size(); i++)
        {
            for (int j = half; j >= stones[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return abs(sum - dp[half] - dp[half]);
    }
};
int main()
{
    Solution sol;
    vector<int> weight{31,26,33,21,40};
    cout << sol.lastStoneWeightII(weight) << endl;
    return 0;
}