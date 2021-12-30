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
    int sumVec(vector<int>& nums)
    {
        int sum = 0;
        for (auto val : nums)
        {
            sum += val;
        }
        return sum;
    }
    int largestSumAfterKNegations(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0 && k != 0)
            {
                k--;
                nums[i] = -1 * nums[i];
            }
        }
        sort(nums.begin(), nums.end());
        if (k % 2 == 1)
        {
            nums[0] = -1 * nums[0];
        }
        return sumVec(nums);
    }
};
int main()
{
    Solution sol;
    vector<int> nums{3,-1,0,2};
    cout << sol.largestSumAfterKNegations(nums, 3) << endl;
    return 0;
}