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
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
class Solution 
{
public:
    vector<vector<int>> levelOrder(Node* root)
    {
        vector<vector<int>> myV;
        queue<Node*> myQ;
        if (root == nullptr)
        {
            return myV;
        }
        myQ.push(root);
        while (!myQ.empty())
        {
            int size = myQ.size();
            vector<int> tmp;
            for (int i = 0; i < size; i++)
            {
                Node* cur = myQ.front();
                myQ.pop();
                tmp.push_back(cur->val);
                for (int j = 0; j < cur->children.size(); j++)
                {
                    myQ.push(cur->children[j]);
                }
            }
            myV.push_back(tmp);
        }
        return myV;
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
    vector<Node*> child;
    child.push_back(f1);
    child.push_back(f2);
    child.push_back(f3);
    root->children = child;
    vector<Node*> child1;
    child1.push_back(f4);
    child1.push_back(f5);
    child1.push_back(f6);
    f1->children = child1;
    sol.printVecArr(sol.levelOrder(root));
    return 0;
}