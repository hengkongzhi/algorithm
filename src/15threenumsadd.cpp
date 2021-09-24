#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
    void pushVec(int a, int b, int c, vector<int>& vec)
    {
        vec.push_back(a);
        vec.push_back(b);
        vec.push_back(c);
        sort(vec.begin(), vec.end());
    }
    bool iSameVec(vector<int>& vec1, vector<int>& vec2)
    {
        for (int i = 0; i < vec1.size(); i++)
        {
            if (vec1[i] != vec2[i])
            {
                return false;
            }
        }
        return true;
    }
    void InVecPush(vector<vector<int>>& myVec, vector<int>& vec)
    {
        if (vec.size() == 0)
        {
            return;
        }
        if (myVec.size() == 0)
        {
            myVec.push_back(vec);
        }
        else
        {
            bool iSame = false;
            for (auto& vecin : myVec)
            {
                if (iSameVec(vecin, vec))
                {
                    iSame = true;
                    break;
                }
            }
            if (iSame == false)
            {
                myVec.push_back(vec);
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        unordered_map<int, int> countMap;
        for (auto a : nums)
        {
            countMap[a]++;
        }
        vector<vector<int>> myVec;
        vector<vector<int>> myVecTmp;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                vector<int> tmp;
                int c = (nums[i] + nums[j]) * -1;
                int count = countMap[c];
                if (count == 0)
                {
                    continue;
                }
                else
                {
                    if (nums[i] == c && nums[j] == c)
                    {
                        if (count >= 3)
                        {
                            pushVec(nums[i], nums[j], c, tmp);
                        }
                    }
                    else if (nums[i] == c || nums[j] == c)
                    {
                        if (count >= 2)
                        {
                            pushVec(nums[i], nums[j], c, tmp);
                        }
                    }
                    else
                    {
                        pushVec(nums[i], nums[j], c, tmp);
                    }
                }
                if (tmp.size() != 0)
                {
                    myVecTmp.push_back(tmp);
                }
            }
        }
        for (auto& tmp : myVecTmp)
        {
            InVecPush(myVec, tmp);
        }
        return myVec;
    }
    vector<vector<int>> threeSum1(vector<int>& nums)
    {
        vector<vector<int>> myVec;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            unordered_set<int> mySet;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (j > i + 2 && nums[j - 2] == nums[j - 1] && nums[j] == nums[j - 1])
                {
                    continue;
                }
                int c = (nums[i] + nums[j]) * -1;
                if (mySet.find(c) != mySet.end())
                {
                   myVec.push_back(vector<int>{nums[i], nums[j], c});
                   mySet.erase(c);
                }
                else
                {
                    mySet.insert(nums[j]);
                }
            }
        }
        return myVec;
    }
    vector<vector<int>> threeSum2(vector<int>& nums)
    {
        vector<vector<int>> myVec;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                if (nums[i] + nums[left] + nums[right] == 0)
                {
                    myVec.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    int rightTmp = right;
                    int leftTmp = left;
                    while (left < rightTmp && nums[rightTmp] == nums[right])
                    {
                        rightTmp--;
                    }
                    if (left < rightTmp)
                    {
                        right = rightTmp;
                    }
                    else
                    {
                        break;
                    }
                    while (leftTmp < right && nums[leftTmp] == nums[left])
                    {
                        leftTmp++;
                    }
                    if (leftTmp < right)
                    {
                        left = leftTmp;
                    }
                    else
                    {
                        break;
                    }
                }
                else if (nums[i] + nums[left] + nums[right] > 0)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
        return myVec;
    }
    void printVecArr(const vector<vector<int>>& myVec)
    {
        for (auto& vec : myVec)
        {
            for (auto num : vec)
            {
                cout << num << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    vector<int> nums{-1,0,1,2,-1,-4};
    Solution solve;
    solve.printVecArr(solve.threeSum2(nums));
    return 0;
}