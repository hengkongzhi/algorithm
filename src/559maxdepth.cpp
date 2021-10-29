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
    int maxDepth(Node* root)
    {
        queue<Node*> myQ;
        if (root == nullptr)
        {
            return 0;
        }
        myQ.push(root);
        int depth = 0;
        while (!myQ.empty())
        {
            depth++;
            int size = myQ.size();
            for (int i = 0; i < size; i++)
            {
                Node* cur = myQ.front();
                myQ.pop();
                for (int j = 0; j < cur->children.size(); j++)
                {
                    myQ.push(cur->children[j]);
                }
            }
        }
        return depth;
    }
    int maxDepth1(Node* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int max = 0;
        for (int i = 0; i < root->children.size(); i++)
        {
            int x = maxDepth1(root->children[i]);
            if (x >= max)
            {
                max = x;
            }
        }
        return max + 1;

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
    cout << sol.maxDepth(root) << endl;
    return 0;
}