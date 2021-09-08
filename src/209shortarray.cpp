#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {

        for (int i = 1; i <= nums.size(); i++)
        {
            int sum = 0;
            for (int j = 0, k = 0; j < nums.size(); j++)
            {
                sum += nums[j];
                k++;
                if (k == i)
                {
                    if (sum >= target)
                    {
                        return i;
                    }
                    j -= (i - 1);
                    sum = 0;
                    k = 0;
                }
            }
        }
        return 0;
    }
    int minSubArrayLen1(int target, vector<int>& nums)
    {
        int sum = 0;
        int sublen = 0;
        int ret = INT32_MAX;
        int j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            while (sum >= target)
            {
                sublen = i - j + 1;
                if (sublen < ret)
                {
                    ret = sublen;
                }
                sum -= nums[j++];
            }
        }
        return ret == INT32_MAX ? 0 : ret;
    } 

};
int main()
{
    Solution m;
    vector<int> nums{2,3,1,2,4,3};
    int target = 7;
    cout << m.minSubArrayLen(target, nums) << endl;
    return 0;
}