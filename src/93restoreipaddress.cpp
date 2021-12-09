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
    vector<string> path;
    vector<string> ret;
    bool isEffect(string& s)
    {
        if (s.size() > 1)
        {
            if (s[0] == '0')
            {
                return false;
            }
        }
        int x = atoi(s.c_str());
        if (x > 255)
        {
            return false;
        }
        return true;
    }
    string add()
    {
        string str = "";
        for (int i = 0; i < path.size(); i++)
        {
            str += path[i];
            if (i != path.size() - 1)
            {
                str += ".";
            }
        }
        return str;
    }
    void back(int start, string& s)
    {
        if (path.size() == 4 && start == s.size())
        {
            ret.push_back(add());
            return;
        }
        if (path.size() == 4)
        {
            return;
        }
        for (int i = start; i < start + 3 && i < s.size(); i++)
        {
            string tmp = s.substr(start, i - start + 1);
            if (isEffect(tmp))
            {
                path.push_back(tmp);
            }
            else
            {
                continue;
            }
            back(i + 1, s);
            path.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s)
    {
        if (s.size() < 4)
        {
            return ret;
        }
        back(0, s);
        return ret;
    }

    void vecPrint()
    {
        for (auto vec : ret)
        {
            cout << vec << " ";
        }
        cout << endl;
    }

};
int main()
{
    Solution sol;
    string s = "1111";
    sol.restoreIpAddresses(s);
    sol.vecPrint();
    return 0;
}