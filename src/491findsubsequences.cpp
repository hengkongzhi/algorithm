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
    bool isSame(int start, int i, vector<int>& nums)
    {
        for (int j = start; j < i; j++)
        {
            if (nums[j] == nums[i])
            {
                return true;
            }
        }
        return false;
    }
    void back(int start, vector<int>& nums)
    {
        if (path.size() >= 2)
        {
            ret.push_back(path);
        }
        if (start == nums.size())
        {
            return;
        }
        int user[201] = {0};
        for (int i = start; i < nums.size(); i++)
        {
            if (user[100 + nums[i]] == 1)
            {
                continue;
            }
            if (path.empty() || nums[i] >= path.back())
            {
                path.push_back(nums[i]);
            }
            else
            {
                continue;
            }
            user[100 + nums[i]] = 1;
            back(i + 1, nums);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums)
    {
        back(0, nums);
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
    vector<int> nums{1,2,3,4,5,6,7,8,9,10,1,1,1,1,1};
    sol.findSubsequences(nums);
    sol.vecPrint();
    return 0;
}