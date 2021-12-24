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
            if (sum >= max)
            {
                max = sum;
            }
            if (sum < nums[i])
            {
                sum = nums[i];
                if (sum >= max)
                {
                    max = sum;
                }
            }
        }
        return max;
    }
};
int main()
{
    Solution sol;
    vector<int> nums{-1,-2};
    cout << sol.maxSubArray(nums) << endl;
    return 0;
}