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
#include <limits.h>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution 
{
public:
    void rightConn(vector<Node*>& myV)
    {
        for (int i = 0; i < myV.size(); i++)
        {
            if ((i + 1) != myV.size())
            {
                myV[i]->next = myV[i + 1];
            }
            else
            {
                myV[i]->next = nullptr;
            }
        }
    }
    Node* connect(Node* root) 
    {
        queue<Node*> myQ;
        if (root == nullptr)
        {
            return root;
        }
        myQ.push(root);
        vector<Node*> myV;
        while (!myQ.empty())
        {
            int size = myQ.size();
            for (int i = 0; i < size; i++)
            {
                Node* cur = myQ.front();
                myQ.pop();
                myV.push_back(cur);
                if (cur->left)
                {
                    myQ.push(cur->left);
                }
                if (cur->right)
                {
                    myQ.push(cur->right);
                }
            }
            rightConn(myV);
            myV.clear();
        }
        return root;
    }
    Node* connect1(Node* root) 
    {
        queue<Node*> myQ;
        if (root == nullptr)
        {
            return root;
        }
        myQ.push(root);
        Node* pre;
        while (!myQ.empty())
        {
            int size = myQ.size();
            for (int i = 0; i < size; i++)
            {
                Node* cur = myQ.front();
                myQ.pop();
                if (i == 0)
                {
                    pre = cur;
                }
                else
                {
                    pre->next = cur;
                    pre = cur;
                }
                if (cur->left)
                {
                    myQ.push(cur->left);
                }
                if (cur->right)
                {
                    myQ.push(cur->right);
                }
            }
            pre->next = nullptr;
        }
        return root;
    }
    void printVec(const vector<int>& myV)
    {
        for (auto vu : myV)
        {
            cout << vu << " ";
        }
        cout << endl;
    }
    void printVecArr(const vector<vector<int>>& myVecArr)
    {
        for (auto myV : myVecArr)
        {
            for (auto value : myV)
            {
                cout << value << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    Solution sol;
    Node* root = new Node(10);
    Node* f1 = new Node(8);
    Node* f2 = new Node(7);
    Node* f3 = new Node(5);
    Node* f4 = new Node(6);
    Node* f5 = new Node(3);
    Node* f6 = new Node(4);
    root->left = f1;
    root->right = f2;
    f1->left = f3;
    f1->right = f4;
    f2->left = f5;
    f2->right = f6;
    cout << sol.connect(root)->next << endl;
    return 0;
}