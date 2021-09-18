#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> tmpVec;
        unordered_set<int> tmpSet;
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                if (nums1[i] == nums2[j])
                {
                    tmpSet.insert(nums1[i]);
                    break;
                }
            }
        }
        for (auto iter = tmpSet.begin(); iter != tmpSet.end(); iter++)
        {
            tmpVec.push_back(*iter);
        }
        return tmpVec;
    }
    vector<int> intersection1(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_set<int> res;
        unordered_set<int> tmp(nums1.begin(), nums1.end());
        for (auto num : nums2)
        {
            if (tmp.find(num) != tmp.end())
            {
                res.insert(num);
            }
        }
        return vector<int>(res.begin(), res.end());
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
    vector<int> nums1{4,9,5};
    vector<int> nums2{9,4,9,8,4};
    Solution solve;
    solve.printVec(solve.intersection1(nums1, nums2));
    return 0;
}