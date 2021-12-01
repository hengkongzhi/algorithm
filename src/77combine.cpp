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
    vector<int> myV;
    int max = 0;
    int kNums;
    void combineTest(vector<int>& nums, int k)
    {
        if (k == 0)
        {
            if (myV.size() == kNums)
            {
                ret.push_back(myV);
            }
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > max)
            {
                int old = max;
                max = nums[i];
                myV.push_back(nums[i]);
                combineTest(nums, k - 1);
                max = old;
                myV.pop_back();
            }
            
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        kNums = k;
        vector<int> nums;
        for (int i = 1; i <= n; i++)
        {
            nums.push_back(i);
        }
        combineTest(nums, k);
        return ret;
    }

    void back(int n, int k, int start)
    {
        if (myV.size() == k)
        {
            ret.push_back(myV);
            return;
        }
        for (int i = start; i <= n - k + 1 + myV.size(); i++)
        {
            myV.push_back(i);
            back(n, k, i + 1);
            myV.pop_back();
        }
    }
    vector<vector<int>> combine1(int n, int k)
    {
        back(n, k, 1);
        return ret;
    }
    void vecPrint()
    {
        for (auto vec : ret)
        {
            for (auto data : vec)
            {
                cout << data << " ";
            }
            cout << endl;
        }
    }

};
int main()
{
    Solution sol;
    sol.combine1(4, 3);
    sol.vecPrint();
    return 0;
}