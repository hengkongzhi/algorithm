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
    vector<int> path;
    vector<vector<int>> ret;
    void forRet(vector<int>& tmp)
    {
        bool flag = false;
        for (int i = 0; i < ret.size(); i++)
        {
            if (tmp.size() == ret[i].size())
            {
                flag = true;
                for (int j = 0; j < tmp.size(); j++)
                {
                    if (tmp[j] != ret[i][j])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    break;
                }
            }
        }
        if (flag == false)
        {
            ret.push_back(tmp);
        }
    }
    void back(vector<int>& vec, int sum)
    {
        if (sum == 0)
        {
            vector<int> tmp = path;
            sort(tmp.begin(), tmp.end());
            forRet(tmp);
            return;
        }
        if (sum < 0 || path.size() >= 150)
        {
            return;
        }
        for (int i = 0; i < vec.size() && sum - vec[i] >= 0; i++)
        {
            path.push_back(vec[i]);
            back(vec, sum - vec[i]);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        if (candidates.size() == 0)
        {
            return ret;
        }
        sort(candidates.begin(), candidates.end());
        back(candidates, target);
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
    vector<int> vec{2,7,6,3,5,1};
    sol.combinationSum(vec, 9);
    sol.vecPrint();
    return 0;
}