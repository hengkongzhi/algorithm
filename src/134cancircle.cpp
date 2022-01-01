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
using namespace std;

class Solution
{
public:
    struct Cmp
    {
        bool operator() (pair<int, int>& it,
                         pair<int, int>& ia)
        {
            return it.second > ia.second;
        }
    };
    int deal(vector<pair<int, int>>& myVec, vector<int>& gas, vector<int>& cost)
    {
        for (auto iter = myVec.begin(); iter != myVec.end(); iter++)
        {
            int start = 0;
            int count = 0;
            bool suc = false;
            for (int i = iter->first; 1 == 1; i++)
            {
                if (i == iter->first)
                {
                    count++;
                }
                if (count == 2)
                {
                    suc = true;
                    break;
                }
                start = start + gas[i] - cost[i];
                if (start < 0)
                {
                    break;
                }
                if (i == gas.size() - 1)
                {
                    i = -1;
                }
            }
            if (suc)
            {
                return iter->first;
            }
        }
        return -1;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        vector<pair<int, int>> myVec;
        int sum0 = 0;
        int sum1 = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            sum0 += gas[i];
            sum1 += cost[i];
            int diff = gas[i] - cost[i];
            if (diff >= 0)
            {
                myVec.push_back(pair<int, int>(i, diff));
            }
        }
        if (sum0 < sum1)
        {
            return -1;
        }
        sort(myVec.begin(), myVec.end(), Cmp());
        return deal(myVec, gas, cost);
    }
    int canCompleteCircuit1(vector<int>& gas, vector<int>& cost)
    {
        int totalSum = 0;
        int curSum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if (curSum < 0)
            {
                start = i + 1;
                curSum = 0;
            }
        }
        if (totalSum < 0)
        {
            return -1;
        }
        return start;
    }
};
int main()
{
    Solution sol;
    vector<int> gas{1,2,3,4,5};
    vector<int> cost{3,4,5,1,2};
    cout << sol.canCompleteCircuit1(gas, cost) << endl;
    return 0;
}