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
    bool judgeEco(string& s)
    {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
        {
            if (s[i] != s[j])
            {
                return false;
            }
        }
        return true;
    }
    bool judgeVec(vector<string>& splite)
    {
        for (auto str : splite)
        {
            if (!judgeEco(str))
            {
                return false;
            }
        }
        return true;
    }
    vector<string> splite;
    vector<vector<string>> ret;
    void back(const string& s)
    {
        if (s.empty())
        {
            if (judgeVec(splite))
            {
                ret.push_back(splite);
            }
            return;
        }
        for (int i = 1; i <= s.size(); i++)
        {
            string tmp(s.begin(), s.begin() + i);
            string sx(s.begin() + i, s.end());
            splite.push_back(tmp);
            back(sx);
            splite.pop_back();
        }
    }
    vector<vector<string>> partition(string s)
    {
        if (s.empty())
        {
            return ret;
        }
        back(s);
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
    string s = "efe";
    sol.partition(s);
    sol.vecPrint();
    return 0;
}