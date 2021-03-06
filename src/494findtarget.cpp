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
    vector<int> path;
    int sum = 0;
    int count = 0;
    int retCount = 0;
    void trace(vector<int>& nums, int start, int target)
    {
        if (count == nums.size())
        {
            if (sum == target)
            {
                retCount++;
            }
            return;
        }
        for (int i = start; i < nums.size(); i++)
        {
            for (int j = 0; j < 2; j++)
            {
                int val = 0;
                if (j == 0)
                {
                    val = nums[i] * (-1);
                }
                else
                {
                    val = nums[i] * 1;
                }
                sum += val;
                count++;
                trace(nums, i + 1, target);
                count--;
                sum -= val;
            }
            
        }
    }
    int findTargetSumWays(vector<int>& nums, int target)
    {
        trace(nums, 0, target);
        return retCount;
    }
    int findTargetSumWays1(vector<int>& nums, int target)
    {
        int sum = 0;
        for (auto val : nums)
        {
            sum += val;
        }
        if (sum - target < 0 || (sum - target) % 2 == 1)
        {
            return 0;
        }
        int right = (sum - target) / 2;
        vector<int> dp(right + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = right; j >= nums[i]; j--)
            {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[right];
    }
};
int main()
{
    Solution sol;
    vector<int> weight{0,0,0,0,1};
    cout << sol.findTargetSumWays1(weight, 1) << endl;
    return 0;
}