#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <unordered_set>
#include <stdlib.h>
#include <math.h>
#include <sstream>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ret;
    vector<int> path;
    void back(vector<int>& nums)
    {
        if (nums.size() == 0)
        {
            ret.push_back(path);
            return;
        }
        for (auto iter = nums.begin(); iter != nums.end(); iter++)
        {
            vector<int> copyVec(nums.begin(), nums.end());
            int pos = iter - nums.begin();
            copyVec.erase(copyVec.begin() + pos);
            path.push_back(*iter);
            back(copyVec);
            path.pop_back();
        }
    }
    void back(vector<int>& nums, vector<bool>& use)
    {
        if (path.size() == nums.size())
        {
            ret.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (use[i])
            {
                continue;
            }
            use[i] = true;
            path.push_back(nums[i]);
            back(nums, use);
            path.pop_back();
            use[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<bool> use;
        for (int i = 0; i < nums.size(); i++)
        {
            use.push_back(false);
        }
        back(nums, use);
        return ret;
    }

    void vecPrint()
    {
        for (auto vec : ret)
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
    Solution sol;
    vector<int> nums{1,2,3};
    sol.permute(nums);
    sol.vecPrint();
    return 0;
}