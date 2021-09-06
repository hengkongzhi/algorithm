#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int size = nums.size();
        int low = 0;
        int high = size - 1;
        return find(nums, low, high, target);

    }
    int search1(vector<int>& nums, int target) 
    {
        int low = 0;
        int high = nums.size();
        int mid = 0;
        while (low < high)
        {
            mid = (low + high) >> 1;
            if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else if (nums[mid] > target)
            {
                high = mid;
            }
            else
            {
                return mid;
            }
        }
        return -1;

    }
    int find(vector<int>& nums, int low, int high, int target)
    {
        int mid = (low + high) / 2;
        if (target < nums[mid])
        {
            if (low > mid - 1)
            {
                return -1;
            }
            else
            {
                return find(nums, low, mid - 1, target);
            }
            
        }
        else if (target > nums[mid])
        {
            if (high < mid + 1)
            {
                return -1;
            }
            else
            {
                return find(nums, mid + 1, high, target);
            }
        }
        else
        {
            return mid;
        }
    }
};
int main()
{
    Solution m;
    vector<int> nums{-1,0,3,5,9,12};
    int target = 9;
    int target1 = 2;
    std::cout << m.search(nums, target) << std::endl;
    std::cout << m.search(nums, target1) << std::endl;
    return 0;
}