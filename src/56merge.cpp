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
        bool operator()(const vector<int>& it, const vector<int>& ia)
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
    void deal(deque<vector<int>>& myDQ, vector<int>& myV)
    {
        if (myDQ.empty())
        {
            myDQ.push_back(myV);
            return;
        }
        vector<int> tmp = myDQ.back();
        if (tmp[1] >= myV[0])
        {
            vector<int> tmp1;
            tmp1.push_back(tmp[0]);
            tmp1.push_back(max(tmp[1], myV[1]));
            myDQ.pop_back();
            myDQ.push_back(tmp1);
        }
        else
        {
            myDQ.push_back(myV);
        }
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end(), Cmp());
        deque<vector<int>> myDQ;
        for (int i = 0; i < intervals.size(); i++)
        {
            deal(myDQ, intervals[i]);
        }
        vector<vector<int>> ret(myDQ.begin(), myDQ.end());
        return ret;
    }
    vector<vector<int>> merge1(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end(), Cmp());
        vector<vector<int>> ret;
        ret.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (ret.back()[1] >= intervals[i][0])
            {
                ret.back()[1] = max(ret.back()[1], intervals[i][1]);
            }
            else
            {
                ret.push_back(intervals[i]);
            }
        }
        return ret;
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
    vector<vector<int>> mer = {{2,3},{4,5},{6,7},{8,9},{1,10}};
    sol.printVec(sol.merge1(mer));
    return 0;
}