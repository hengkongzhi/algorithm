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
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int max = INT32_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum < nums[i])
            {
                sum = nums[i];
            }
            if (sum >= max)
            {
                max = sum;
            }
        }
        return max;
    }
    int maxSubArray1(vector<int>& nums)
    {
        int max = INT32_MIN;
        int ret = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ret += nums[i];
            if (ret > max)
            {
                max = ret;
            }
            if (ret < 0)
            {
                ret = 0;
            }
        }
        return max;
    }
    int maxSubArray2(vector<int>& nums)
    {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int result = dp[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            if (dp[i] > result)
            {
                result = dp[i];
            }
        }
        return result;
    }
};
int main()
{
    Solution sol;
    vector<int> nums{-1,-2};
    cout << sol.maxSubArray2(nums) << endl;
    return 0;
}