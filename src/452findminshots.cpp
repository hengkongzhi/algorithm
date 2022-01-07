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
    void getIntersect(stack<vector<int>>& myStack, vector<int>& myV)
    {
        if (myStack.empty())
        {
            myStack.push(myV);
            return;
        }
        auto onTop = myStack.top();
        if (onTop[1] >= myV[0])
        {
            vector<int> tmp;
            tmp.push_back(myV[0]);
            tmp.push_back(min(myV[1], onTop[1]));
            myStack.pop();
            myStack.push(tmp);
        }
        else
        {
            myStack.push(myV);
        }
    }
    int findMinArrowShots(vector<vector<int>>& points)
    {
        sort(points.begin(), points.end(), Cmp());
        stack<vector<int>> myStack;
        for (int i = 0; i < points.size(); i++)
        {
            getIntersect(myStack, points[i]);
        }
        return myStack.size();

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
    vector<vector<int>> cost{{10,16},{2,8},{1,6},{7,12}};
    cout << sol.findMinArrowShots(cost) << endl;
    return 0;
}