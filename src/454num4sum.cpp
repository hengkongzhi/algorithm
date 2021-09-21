#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, 
                     vector<int>& nums3, vector<int>& nums4)
    {
        int ret = 0;
        unordered_map<int, int> mapcout1;
        unordered_map<int, int> mapcout2;
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                auto iter = mapcout1.find(nums1[i] + nums2[j]);
                if (iter == mapcout1.end())
                {
                    mapcout1.insert(pair<int, int>(nums1[i] + nums2[j], 1));
                }
                else
                {
                    iter->second++;
                }
            }
        }
        for (int i = 0; i < nums3.size(); i++)
        {
            for (int j = 0; j < nums4.size(); j++)
            {
                auto iter = mapcout2.find((nums3[i] + nums4[j]) * -1);
                if (iter == mapcout2.end())
                {
                    mapcout2.insert(pair<int, int>((nums3[i] + nums4[j]) * -1, 1));
                }
                else
                {
                    iter->second++;
                }
            }
        }
        for (auto iter = mapcout1.begin(); iter != mapcout1.end(); iter++)
        {
            auto fter = mapcout2.find(iter->first);
            if (fter != mapcout2.end())
            {
                ret += iter->second * fter->second;
            }
        }
        return ret;
    }
    int fourSumCount1(vector<int>& nums1, vector<int>& nums2, 
                     vector<int>& nums3, vector<int>& nums4)
    {
        int ret = 0;
        unordered_map<int, int> mapcout;
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                auto iter = mapcout.find(nums1[i] + nums2[j]);
                if (iter == mapcout.end())
                {
                    mapcout.insert(pair<int, int>(nums1[i] + nums2[j], 1));
                }
                else
                {
                    iter->second++;
                }
            }
        }
        for (int i = 0; i < nums3.size(); i++)
        {
            for (int j = 0; j < nums4.size(); j++)
            {
                auto iter = mapcout.find((nums3[i] + nums4[j]) * -1);
                if (iter != mapcout.end())
                {
                    ret += iter->second;
                }
            }
        }
        return ret;        
    }
    int fourSumCount2(vector<int>& nums1, vector<int>& nums2, 
                     vector<int>& nums3, vector<int>& nums4)
    {
        unordered_map<int , int> umap;
        int ret = 0;
        for (int num1 : nums1)
        {
            for (int num2 : nums2)
            {
                umap[num1 + num2]++;
            }
        }
        for (int num3 : nums3)
        {
            for (int num4 : nums4)
            {
                if (umap.find(0 - (num3 + num4)) != umap.end())
                {
                    ret += umap[0 - (num3 + num4)];
                }
                
            }
        }
        return ret;
    }
};
int main()
{
    vector<int> nums1{1, 2};
    vector<int> nums2{-2, -1};
    vector<int> nums3{-1, 2};
    vector<int> nums4{0, 2};
    Solution solve;
    cout << solve.fourSumCount2(nums1, nums2, nums3, nums4) << endl;
    return 0;
}