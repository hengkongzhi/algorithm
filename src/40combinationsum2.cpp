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
    void back(int sum, vector<int>& cand, int start)
    {
        if (sum == 0)
        {
            ret.push_back(path);
            return;
        }
        if (sum < 0)
        {
            return;
        }
        for (int i = start; i < cand.size() && sum - cand[i] >= 0; i++)
        {
            if (i - 1 >= 0 && cand[i] == cand[i - 1] && i != start)
            {
                continue;
            }
            path.push_back(cand[i]);
            back(sum - cand[i], cand, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        if (candidates.size() == 0)
        {
            return ret;
        }
        sort(candidates.begin(), candidates.end());
        back(target, candidates, 0);
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
    vector<int> vec{10,1,2,7,6,1,5};
    sol.combinationSum2(vec, 8);
    sol.vecPrint();
    return 0;
}