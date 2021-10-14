#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <stdlib.h>
using namespace std;
class Solution 
{
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> myStack;
        for (string& it : tokens)
        {
            if (it == "+")
            {
                int a = myStack.top();
                myStack.pop();
                int b = myStack.top();
                myStack.pop();
                myStack.push(a + b);
            }
            else if (it == "-")
            {
                int a = myStack.top();
                myStack.pop();
                int b = myStack.top();
                myStack.pop();
                myStack.push(b - a);
            }
            else if (it == "*")
            {
                int a = myStack.top();
                myStack.pop();
                int b = myStack.top();
                myStack.pop();
                myStack.push(b * a);
            }
            else if (it == "/")
            {
                int a = myStack.top();
                myStack.pop();
                int b = myStack.top();
                myStack.pop();
                myStack.push(b / a);
            }
            else
            {
                myStack.push(atoi(it.c_str()));
            }
        }
        return myStack.top();
    }
};
int main()
{
    Solution sol;
    vector<string> myV{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << sol.evalRPN(myV) << endl;
    return 0;
}