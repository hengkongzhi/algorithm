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
#include <sstream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int num) : val(num), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int num, TreeNode* l, TreeNode* r) : val(0), left(l), right(r)
    {
    }

};
class Solution 
{
public:
    bool findNode(TreeNode* root, TreeNode* t2)
    {
        if (root == nullptr)
        {
            return false;
        }
        bool leftFd = false;
        bool rightFd = false;
        if (root->left)
        {
            leftFd = findNode(root->left, t2);
        }
        if (root->val == t2->val)
        {
            return true;
        }
        if (root->right)
        {
            rightFd = findNode(root->right, t2);
        }
        return leftFd || rightFd;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (findNode(p, q))
        {
            return p;
        }
        if (findNode(q, p))
        {
            return q;
        }
        queue<TreeNode*> myQ;
        myQ.push(root);
        TreeNode* ancestor = nullptr;
        while (!myQ.empty())
        {
            TreeNode* cur = myQ.front();
            myQ.pop();
            if (cur->val == q->val || cur->val == p->val)
            {
                return ancestor;
            }
            if (findNode(cur, p) && findNode(cur, q))
            {
                ancestor = cur;
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
        return ancestor;

    }
    void printVec(const vector<int>& myV)
    {
        for (auto& val : myV)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    void preOrderPrint(TreeNode* cur)
    {
        if (cur == nullptr)
        {
            return;
        }
        cout << cur->val << endl;
        preOrderPrint(cur->left);
        preOrderPrint(cur->right);
    }

};
int main()
{
    Solution sol;
    TreeNode* root = new TreeNode(3);
    TreeNode* f1 = new TreeNode(2);
    TreeNode* f2 = new TreeNode(4);
    TreeNode* f4 = new TreeNode(1);
    TreeNode* f6 = new TreeNode(5);
    root->left = f1;
    root->right = f2;
    f1->left = f4;
    f2->right = f6;
    cout << sol.lowestCommonAncestor(root, f1, f4)->val << endl;
    return 0;
}