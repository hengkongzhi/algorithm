#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return {};
    }
    vector<int> twoSum1(vector<int>& nums, int target)
    {
        unordered_map<int, int> myMap;
        for (int i = 0; i < nums.size(); i++)
        {
            auto iter = myMap.find(target - nums[i]);
            if (iter != myMap.end())
            {
                return {iter->second, i};
            }
            else
            {
                myMap.insert(pair<int, int>(nums[i], i));
            }
        }
        return {};

    }
    void printVec(const vector<int>& nums1)
    {
        for (int i = 0; i < nums1.size(); i++)
        {
            cout << nums1[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    vector<int> nums1{2,7,11,15};
    vector<int> nums2{3,3};
    Solution solve;
    solve.printVec(solve.twoSum1(nums2, 6));
    return 0;
}