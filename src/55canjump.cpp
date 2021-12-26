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
    bool judge(int first, int last, int count, vector<int>& nums)
    {
        int j = 0;
        for (int i = last; i >= first; i--)
        {
            if (nums[i] - j > count)
            {
                return true;
            }
            j++;
        }
        return false;
    }
    bool canJump(vector<int>& nums)
    {
        if (nums.size() == 0)
        {
            return false;
        }
        if (nums[0] == 0 && nums.size() != 1)
        {
            return false;
        }
        if (nums[0] == 0 && nums.size() == 1)
        {
            return true;
        }
        int first = 0;
        int last = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                if (count == 0)
                {
                    last = i - 1;
                }
                if (i != nums.size() - 1)
                {
                    count++;
                }
            }
            else
            {
                if (count != 0)
                {
                    if (!judge(first, last, count, nums))
                    {
                        return false;
                    }
                    first = i;
                }
                count = 0;
            }
            if (i == nums.size() - 1 && nums[i] == 0)
            {
                if (!judge(first, last, count, nums))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
int main()
{
    Solution sol;
    vector<int> nums{8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5};
    cout << sol.canJump(nums) << endl;
    return 0;
}