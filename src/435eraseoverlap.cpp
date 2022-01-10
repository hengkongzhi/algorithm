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
            if (it[1] < ia[1])
            {
                return true;
            }
            else if (it[1] > ia[1])
            {
                return false;
            }
            else
            {
                return it[0] < ia[0];
            }
        }
    };
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end(), Cmp());
        int count = 0;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < intervals[i - 1][1])
            {
                intervals[i][1] = intervals[i - 1][1];
                count++;
            }
        }
        return count;
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