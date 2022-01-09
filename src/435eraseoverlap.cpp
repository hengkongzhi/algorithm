#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <stdlib.h>
#include <math.h>
#include <sstream>
#include <list>
using namespace std;

class Solution
{
public:
    struct Cmp
    {
        bool operator() (vector<int>& it, vector<int>& ia)
        {
            if (it[0] < ia[0])
            {
                return true;
            }
            else if (it[0] > ia[0])
            {
                return false;
            }
            else
            {
                return it[1] < ia[1];
            }
        }
    };
    bool judge(vector<vector<int>>& inter, vector<int>& val)
    {
        vector<int> nVal(val.begin(), val.end());
        for (int i = 0; i < inter.size(); i++)
        {
            if (inter[i][0] >= nVal[0] && inter[i][1] <= nVal[1])
            {
                return true;
            }
            if (nVal[0] >= inter[i][0] && nVal[1] <= inter[i][1])
            {
                return true;
            }
            if (nVal[0] <= inter[i][1])
            {
                nVal[0] = inter[i][0];
            }
        }
        inter.push_back(val);
        return false;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end(), Cmp());
        vector<vector<int>> ret;
        for (int i = 0; i < intervals.size(); i++)
        {
            judge(ret, intervals[i]);
        }
        return intervals.size() - ret.size();
    }
    void printVec(const vector<vector<int>>& real)
    {
        for (auto val : real)
        {
            for (auto num : val)
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
    vector<vector<int>> cost{{1,100},{11,22},{1,11},{2,12}};
    cout << sol.eraseOverlapIntervals(cost) << endl;
    return 0;
}