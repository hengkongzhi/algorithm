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
    string removeDuplicates(string s)
    {
        stack<char> myStack;
        for (int i = 0; i < s.size(); i++)
        {
            if (!myStack.empty())
            {
                if (myStack.top() == s[i])
                {   
                    myStack.pop();
                }
                else
                {
                    myStack.push(s[i]);
                }
            }
            else
            {
                myStack.push(s[i]);
            }
        }
        s.resize(myStack.size());
        for (int i = s.size() - 1; i >= 0; i--)
        {
            s[i] = myStack.top();
            myStack.pop();
        }
        return s;
    }
    string removeDuplicates1(string s)
    {
        string res;
        for (char& x : s)
        {
            if (!res.empty() && res.back() == x)
            {
                res.pop_back();
            }
            else
            {
                res.push_back(x);
            }
        }
        return res;
    }
};
int main()
{
    string str = "abbaca";
    Solution sol;
    cout << sol.removeDuplicates1(str) << endl;
    return 0;
}