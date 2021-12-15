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
            if (i > 0 && use[i - 1] == false && nums[i] == nums[i - 1])
            {
                continue;
            }
            path.push_back(nums[i]);
            use[i] = true;
            back(nums, use);
            path.pop_back();
            use[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        
        sort(nums.begin(), nums.end());
        vector<bool> use(nums.size(), false);
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
    vector<int> nums{1,1,1,2};
    sol.permuteUnique(nums);
    sol.vecPrint();
    return 0;
}