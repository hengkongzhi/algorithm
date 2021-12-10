#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <map>
#include <stdlib.h>
#include <math.h>
#include <sstream>
using namespace std;
class Solution 
{
public:
    vector<vector<int>> ret;
    vector<int> path;
    void back(int start, vector<int>& nums)
    {
        ret.push_back(path);
        if (start == nums.size())
        {
            return;
        }
        for (int i = start; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            back(i + 1, nums);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums)
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
    vector<int> nums{1, 2, 3};
    sol.subsets(nums);
    sol.vecPrint();
    return 0;
}