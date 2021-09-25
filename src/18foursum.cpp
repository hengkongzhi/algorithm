#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> myVec;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            for (int j = nums.size() - 1; j > i + 2; j--)
            {
                if (j < nums.size() - 1 && nums[j] == nums[j + 1])
                {
                    continue;
                }
                int maxLeft = i;
                int maxRight = j;
                int left = i + 1;
                int right = j - 1;
                while (left < right)
                {
                    long sum = 0;
                    sum += nums[maxLeft];
                    sum += nums[maxRight];
                    sum += nums[left];
                    sum += nums[right];
                    if (sum == target)
                    {
                        myVec.push_back(vector<int>{nums[maxLeft], nums[left], nums[right], nums[maxRight]});
                        while (left < right && nums[left] == nums[left + 1])
                        {
                            left++;
                        }
                        while (left < right && nums[right] == nums[right - 1])
                        {
                            right--;
                        }
                        left++;
                        right--;
                    }
                    else if (sum < target)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
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
    vector<int> nums{1,0,-1,0,-2,2};
    Solution m;
    m.printVecArr(m.fourSum(nums, 0));
    return 0;
}