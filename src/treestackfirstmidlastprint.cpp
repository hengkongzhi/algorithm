#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <map>
#include <stdlib.h>
using namespace std;
struct Tree
{
    int val;
    Tree* left;
    Tree* right;
    Tree() : val(0), left(nullptr), right(nullptr)
    {
    }
    Tree(int num) : val(num), left(nullptr), right(nullptr)
    {
    }
    Tree(int num, Tree* l, Tree* r) : val(0), left(l), right(r)
    {
    }

};
class Solution 
{
public:
    vector<int> treeFirstPrint(Tree* root)
    {
        vector<int> myV;
        stack<Tree*> myS;
        myS.push(root);
        Tree* cur;
        while (!myS.empty())
        {
            cur = myS.top();
            myV.push_back(cur->val);
            myS.pop();
            if (cur->right)
            {
                myS.push(cur->right);
            }
            if (cur->left)
            {
                myS.push(cur->left);
            }
        }
        return myV;
    }
    vector<int> treeFirstPrint1(Tree* root)
    {
        vector<int> myV;
        stack<Tree*> myS;
        Tree* cur;
        if (root != nullptr)
        {
            myS.push(root);
        }
        while (!myS.empty())
        {
            cur = myS.top();
            if (cur)
            {
                myS.pop();
                if (cur->right)
                {
                    myS.push(cur->right);
                }
                if (cur->left)
                {
                    myS.push(cur->left);
                }
                myS.push(cur);
                myS.push(nullptr);
            }
            else
            {
                myS.pop();
                cur = myS.top();
                myS.pop();
                myV.push_back(cur->val);
            }
        }
        return myV;
    }

    vector<int> treeMidPrint(Tree* root)
    {
        vector<int> myV;
        if (root == nullptr)
        {
            return myV;
        }
        stack<Tree*> myS;
        myS.push(root);
        Tree* cur;
        while (!myS.empty())
        {
            cur = myS.top();
            while (cur->left && cur->left->val != -101)
            {
                myS.push(cur->left);
                cur = cur->left;
            }
            myV.push_back(cur->val);
            cur->val = -101;
            myS.pop();
            if (cur->right)
            {
                myS.push(cur->right);
            }
        }

        return myV;
    }
    vector<int> treeMidPrint1(Tree* root)
    {
        vector<int> myV;
        stack<Tree*> myS;
        Tree* cur = root;
        while (cur || !myS.empty())
        {
            if (cur)
            {
                myS.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = myS.top();
                myS.pop();
                myV.push_back(cur->val);
                cur = cur->right;
            }
        }
        return myV;
    }
    vector<int> treeMidPrint2(Tree* root)
    {
        vector<int> myV;
        stack<Tree*> myS;
        Tree* cur;
        if (root != nullptr)
        {
            myS.push(root);
        }
        while (!myS.empty())
        {
            cur = myS.top();
            if (cur)
            {
                myS.pop();
                if (cur->right)
                {
                    myS.push(cur->right);
                }
                myS.push(cur);
                myS.push(nullptr);
                if (cur->left)
                {
                    myS.push(cur->left);
                }
            }
            else
            {
                myS.pop();
                cur = myS.top();
                myS.pop();
                myV.push_back(cur->val);
            }
        }
        return myV;
    }
    vector<int> treeLastPrint(Tree* root)
    {
        vector<int> myV;
        if (root == nullptr)
        {
            return myV;
        }
        stack<Tree*> myS;
        myS.push(root);
        Tree* cur;
        while (!myS.empty())
        {
            cur = myS.top();
            while (cur->left && cur->left->val != -101)
            {
                myS.push(cur->left);
                cur = cur->left;
            }

            if (cur->right && cur->right->val != -101)
            {
                myS.push(cur->right);
            }
            else
            {
                myV.push_back(cur->val);
                cur->val = -101;
                myS.pop();
            }

        }

        return myV;        
    }
    vector<int> treeLastPrint1(Tree* root)
    {
        vector<int> myV;
        if (root == nullptr)
        {
            return myV;
        }
        stack<Tree*> myS;
        myS.push(root);
        Tree* cur;
        while (!myS.empty())
        {
            cur = myS.top();
            myV.push_back(cur->val);
            myS.pop();
            if (cur->left)
            {
                myS.push(cur->left);
            }
            if (cur->right)
            {
                myS.push(cur->right);
            }

        }
        reverse(myV.begin(), myV.end());
        return myV;
    }
    vector<int> treeLastPrint2(Tree* root)
    {
        vector<int> myV;
        stack<Tree*> myS;
        Tree* cur;
        if (root != nullptr)
        {
            myS.push(root);
        }
        while (!myS.empty())
        {
            cur = myS.top();
            if (cur)
            {
                myS.push(nullptr);
                if (cur->right)
                {
                    myS.push(cur->right);
                }
                if (cur->left)
                {
                    myS.push(cur->left);
                }
            }
            else
            {
                myS.pop();
                cur = myS.top();
                myS.pop();
                myV.push_back(cur->val);
            }
        }
        return myV;
    }
    void printVec(const vector<int>& myV)
    {
        for (auto num : myV)
        {
            cout << num << ",";
        }
        cout << endl;
    }
};
int main()
{
    Solution sol;
    Tree* root = new Tree(10);
    Tree* f1 = new Tree(8);
    Tree* f2 = new Tree(7);
    Tree* f3 = new Tree(5);
    Tree* f4 = new Tree(6);
    Tree* f5 = new Tree(3);
    Tree* f6 = new Tree(4);
    root->left = f1;
    root->right = f2;
    f1->left = f3;
    f1->right = f4;
    f2->left = f5;
    f2->right = f6;

    sol.printVec(sol.treeFirstPrint1(root));
    sol.printVec(sol.treeMidPrint2(root));
    sol.printVec(sol.treeLastPrint2(root));
    return 0;
}