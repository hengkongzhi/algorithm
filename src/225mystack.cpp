#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
class MyStack {
private:
    queue<int> que1;
    queue<int> que2;
public:
    MyStack() {

    }
    
    void push(int x) {
        que1.push(x);

    }
    
    int pop() {
        if (que1.empty())
        {
            while (!que2.empty())
            {
                int tmpValue = que2.front();
                que2.pop();
                que1.push(tmpValue);
            }
        }
        int curV = -1;
        while (!que1.empty())
        {
            curV = que1.front();
            que1.pop();
            if (!que1.empty())
            {
                que2.push(curV);
            }
        }
        return curV;

    }
    
    int top() {
        int value = pop();
        if (value != -1)
        {
            que1.push(value);
        }
        return value;
    }
    
    bool empty() {
        if (que1.empty() && que2.empty())
        {
            return true;
        }
        return false;
    }
    void printStack()
    {
        queue<int> tmpQ1(que1);
        queue<int> tmpQ2(que2);
        cout << "-----------------" << endl;
        while (!tmpQ2.empty())
        {
            cout << tmpQ2.front() << endl;
            tmpQ2.pop();
        }
        while (!tmpQ1.empty())
        {
            cout << tmpQ1.front() << endl;
            tmpQ1.pop();
        }
    }
};
int main()
{
    MyStack myStack;
    myStack.push(1);
    myStack.printStack();
    myStack.push(2);
    myStack.printStack();
    myStack.top(); // 返回 2
    myStack.printStack();
    myStack.pop(); // 返回 2
    myStack.printStack();
    myStack.empty(); // 返回 False
    return 0;
}