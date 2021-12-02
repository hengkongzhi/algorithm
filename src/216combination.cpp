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
    vector<vector<int>> tmpRet;
    vector<int> path;
    void com(int k, int start)
    {
        if (path.size() == k)
        {
            tmpRet.push_back(path);
            return;
        }
        for (int i = start; i <= 9 - k + 1 + path.size(); i++)
        {
            path.push_back(i);
            com(k, i + 1);
            path.pop_back();
        }
    }

    void findRet(int n)
    {
        for (auto vec : tmpRet)
        {
            int sum = 0;
            for (auto num : vec)
            {
                sum += num;
            }
            if (sum == n)
            {
                ret.push_back(vec);
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        com(k, 1);
        findRet(n);
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
    sol.combinationSum3(3, 9);
    sol.vecPrint();
    return 0;
}