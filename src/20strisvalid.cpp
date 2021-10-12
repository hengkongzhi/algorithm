#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
class Solution 
{
public:
    bool isValid(string s)
    {
        int len = s.size();
        if (len % 2 != 0)
        {
            return false;
        }
        stack<char> mySta;
        for (int i = 0; i < len; i++)
        {
            switch (s[i])
            {
                case '(':
                case '[':
                case '{':
                    mySta.push(s[i]);
                    break;
                case ')':
                    if (mySta.empty())
                    {
                        return false;
                    }
                    if (mySta.top() != '(')
                    {
                        return false;
                    }
                    else
                    {
                        mySta.pop();
                    }
                    break;
                case ']':
                    if (mySta.empty())
                    {
                        return false;
                    }
                    if (mySta.top() != '[')
                    {
                        return false;
                    }
                    else
                    {
                        mySta.pop();
                    }
                    break;
                case '}':
                    if (mySta.empty())
                    {
                        return false;
                    }
                    if (mySta.top() != '{')
                    {
                        return false;
                    }
                    else
                    {
                        mySta.pop();
                    }
                    break;
                default:
                    return false;                 
            }
        }
        if (mySta.empty())
        {
            return true;
        }
        return false;
    }
    bool isValid1(string s)
    {
        stack<char> myStak;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                myStak.push(')');
            }
            else if (s[i] == '[')
            {
                myStak.push(']');
            }
            else if (s[i] == '{')
            {
                myStak.push('}');
            }
            else if (myStak.empty() || s[i] != myStak.top())
            {
                return false;
            }
            else
            {
                myStak.pop();
            }
        }
        return myStak.empty();
    }
};
int main()
{
    string str = "()([()])()";
    Solution sol;
    cout << (sol.isValid1(str) ? "TRUE" : "FALSE") << endl;
    return 0;
}