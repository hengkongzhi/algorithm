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
    vector<map<int, int>> ret;
    map<int, int> path;
    bool judgeOk(int level, int num)
    {
        for (int i = 1; i < level; i++)
        {
            int x = level - i;
            int y = path[i] - num;
            if (x == 0 || y == 0 || abs(x) == abs(y))
            {
                return false;
            } 
        }
        return true;
    }
    bool back(int level, int n)
    {
        if (level == n + 1)
        {
            ret.push_back(path);
            return true;
        }
        for (int i = 1; i <= n; i++)
        {
            if (judgeOk(level, i))
            {
                path[level] = i;
            }
            else
            {
                continue;
            }
            back(level + 1, n);
        }
        return false;
    }
    void addDot(string& tmp, int x, int n)
    {
        for (int i = 1; i <= n; i++)
        {
            if (i == x)
            {
                tmp += "Q";
            }
            else
            {
                tmp += ".";
            }
            
        }
    }
    void retString(vector<vector<string>>& tmp, int n)
    {
        for (auto m : ret)
        {
            vector<string> vecStr;
            for (int i = 1; i <= n; i++)
            {
                string kStr = "";
                addDot(kStr, m[i], n);
                vecStr.push_back(kStr);
            }
            tmp.push_back(vecStr);
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> tmp;
        back(1, n);
        retString(tmp, n);
        return tmp;
    }
    void vecPrint(const vector<vector<string>>& tmp)
    {
        for (auto vec : tmp)
        {
            for (auto p : vec)
            {
                cout << p;
                cout << endl;
            }
            cout << "------------------";
            cout << endl;
        }
    }

};
int main()
{
    Solution sol;
    sol.vecPrint(sol.solveNQueens(5));
    return 0;
}