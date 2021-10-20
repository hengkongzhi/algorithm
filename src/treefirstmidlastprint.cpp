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

    void funcF(vector<int>& myV, Tree* cur)
    {
        if (cur == nullptr)
        {
            return;
        }
        myV.push_back(cur->val);
        funcF(myV, cur->left);
        funcF(myV, cur->right);

    }
    vector<int> treeFirstPrint(Tree* root)
    {
        vector<int> myV;
        funcF(myV, root);
        return myV;
    }
    void funcMid(vector<int>& myV, Tree* cur)
    {
        if (cur == nullptr)
        {
            return;
        }
        funcMid(myV, cur->left);
        myV.push_back(cur->val);
        funcMid(myV, cur->right);
    }
    vector<int> treeMidPrint(Tree* root)
    {
        vector<int> myV;
        funcMid(myV, root);
        return myV;
    }
    void funcLast(vector<int>& myV, Tree* cur)
    {
        if (cur == nullptr)
        {
            return;
        }
        funcLast(myV, cur->left);
        funcLast(myV, cur->right);
        myV.push_back(cur->val);
    }
    vector<int> treeLastPrint(Tree* root)
    {
        vector<int> myV;
        funcLast(myV, root);
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

    sol.printVec(sol.treeFirstPrint(root));
    sol.printVec(sol.treeMidPrint(root));
    sol.printVec(sol.treeLastPrint(root));
    return 0;
}