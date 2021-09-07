#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int count = 0;
        for (auto& var : nums)
        {
            if (var == val)
            {
                count++;
            }
        }
        int ret = nums.size() - count;
        int j = nums.size() - 1;
        for (int i = 0; i < ret; i++)
        {
            while (nums[i] == val)
            {
                swap(&nums[i], &nums[j--]);
            }
        }
        return ret;

    }
    int removeElement1(vector<int>& nums, int val)
    {
        int slow = 0;
        for (int speed = 0; speed < nums.size(); speed++)
        {
            if (nums[speed] != val)
            {
                nums[slow++] = nums[speed];
            }
        }
        return slow;
    }
    void swap(int* a, int* b)
    {
        int temp = 0;
        temp = *a;
        *a = *b;
        *b = temp;
    }
};
int main()
{
    Solution m;
    vector<int> nums{0,1,2,2,3,0,4,2};
    int target = 0;
    int target1 = 2;
    cout << m.removeElement(nums, target) << endl;
    cout << m.removeElement(nums, target1) << endl;
    return 0;
}