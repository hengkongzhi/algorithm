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
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (p == nullptr && q != nullptr)
        {
            return false;
        }
        else if (p != nullptr && q == nullptr)
        {
            return false;
        }
        else if (p == nullptr && q == nullptr)
        {
            return true;
        }
        else if (p->val != q->val)
        {
            return false;
        }
        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        return left && right;
    }
    bool isSameTree1(TreeNode* p, TreeNode* q)
    {
        if (p == nullptr && q != nullptr)
        {
            return false;
        }
        else if (p != nullptr && q == nullptr)
        {
            return false;
        }
        else if (p == nullptr && q == nullptr)
        {
            return true;
        }
        stack<TreeNode*> myStak1;
        stack<TreeNode*> myStak2;
        myStak1.push(p);
        myStak2.push(q);
        while (!myStak1.empty() && !myStak2.empty())
        {
            TreeNode* cur1 = myStak1.top();
            TreeNode* cur2 = myStak2.top();
            myStak1.pop();
            myStak2.pop();
            if (cur1->val != cur2->val)
            {
                return false;
            }
            if (cur1->left == nullptr && cur2->left != nullptr)
            {
                return false;
            }
            else if (cur1->left != nullptr && cur2->left == nullptr)
            {
                return false;
            }
            if (cur1->right != nullptr && cur2->right == nullptr)
            {
                return false;
            }
            else if (cur1->right == nullptr && cur2->right != nullptr)
            {
                return false;
            }
            if (cur1->right)
            {
                myStak1.push(cur1->right);
            }
            if (cur2->right)
            {
                myStak2.push(cur2->right);
            }
            if (cur1->left)
            {
                myStak1.push(cur1->left);
            }
            if (cur2->left)
            {
                myStak2.push(cur2->left);
            }
        }
        return myStak1.empty() && myStak2.empty();
    }

};
int main()
{
    Solution sol;
    TreeNode* root = new TreeNode(1);
    TreeNode* f1 = new TreeNode(2);
    TreeNode* f2 = new TreeNode(3);
    TreeNode* f4 = new TreeNode(4);
    TreeNode* f6 = new TreeNode(5);
    root->left = f1;
    root->right = f2;
    f1->left = f4;
    f4->right = f6;
    cout << (sol.isSameTree1(root, root) ? "TRUE" : "FALSE") << endl;
    return 0;
}