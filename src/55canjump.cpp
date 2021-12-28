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
    bool deal(int val, vector<int>& myVec)
    {
        int count = 0;
        int i = myVec.size() - 1;
        for (; i >= 0; i--)
        {
            if (myVec[i] < val)
            {
                break;
            }
            count++;
        }
        if (count == 0)
        {
            return true;
        }
        auto iter = myVec.begin() + i + 1;
        auto iter1 = myVec.end();
        vector<int> newVec(iter, iter1);
        myVec.clear();
        myVec.assign(newVec.begin(), newVec.end());

        return false;
    }
    bool canJump1(vector<int>& nums)
    {
        vector<int> myVec;
        if (nums.size() == 0)
        {
            return true;
        }
        if (nums.size() == 1 && nums[0] == 0)
        {
            return true;
        }
        if (nums[0] == 0)
        {
            return false;
        }
        for (int i = 1; i < nums.size() - 1; i++)
        {
            if (nums[i] == 0)
            {
                myVec.push_back(i);
            }
        }
        if (myVec.empty())
        {
            return true;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0 && deal(i + nums[i], myVec))
            {
                return true;
            }
            else
            {
                if (nums[i] == 0)
                {
                    if (i >= myVec[0])
                    {
                        return false;
                    }
                }
                else if (i + 1 < nums.size() - 1 &&
                    nums[i + 1] == 0 &&
                    myVec[0] <= i + 1)
                {
                    return false;
                }
            }
        }
        if (myVec.empty())
        {
            return true;
        }
        return false;
    }
    bool canJump2(vector<int>& nums)
    {
        int lDistance = nums.size() - 1;
        int max = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i <= max)
            {
                if (i + nums[i] > max)
                {
                    max = i + nums[i];
                }
            }
            if (max >= lDistance)
            {
                return true;
            }
        }
        return false;
    }
    bool canJump3(vector<int>& nums)
    {
        int lDistance = nums.size() - 1;
        int cover = 0;
        for (int i = 0; i <= cover; i++)
        {
            cover = max(i + nums[i], cover);
            if (cover >= lDistance)
            {
                return true;
            }
        }
        return false;
    }
};
int main()
{
    Solution sol;
    vector<int> nums{8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5};
    cout << sol.canJump2(nums) << endl;
    return 0;
}