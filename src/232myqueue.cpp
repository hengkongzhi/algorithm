#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
class MyQueue 
{
private:
    stack<int> pushA;
    stack<int> popB;
public:
    MyQueue() {

    }
    
    void push(int x) {
        pushA.push(x);
    }
    
    int pop() {
        if (popB.empty())
        {
            while (!pushA.empty())
            {
                int pValue = pushA.top();
                pushA.pop();
                popB.push(pValue);
            }
        }
        if (!popB.empty())
        {
            int pValue = popB.top();
            popB.pop();
            return pValue;
        }
        return -1;
    }
    
    int peek() {
        int pValue = pop();
        popB.push(pValue);
        return pValue;
    }
    
    bool empty() {
        if (pushA.empty() && popB.empty())
        {
            return true;
        }
        return false;
    }
    void printQueue()
    {
        if (empty())
        {
            return;
        }
        cout << "------------------" << endl;
        stack<int> a = pushA;
        stack<int> b = popB;
        while (!b.empty())
        {
            cout << b.top() << endl;
            b.pop();
        }
        while (!a.empty())
        {
            b.push(a.top());
            a.pop();
        }
        while (!b.empty())
        {
            cout << b.top() << endl;
            b.pop();
        }
    }
};
int main()
{
    MyQueue myQueue;
    myQueue.push(1); // queue is: [1]
    myQueue.printQueue();
    myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
    myQueue.printQueue();
    myQueue.peek(); // return 1
    myQueue.printQueue();
    myQueue.pop(); // return 1, queue is [2]
    myQueue.printQueue();
    myQueue.empty(); // return false 
    return 0;
}