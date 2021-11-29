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
    int sum = 0;
    TreeNode* convertBST(TreeNode* root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (root->right)
        {
            convertBST(root->right);
        }
        sum += root->val;
        root->val = sum;
        if (root->left)
        {
            convertBST(root->left);
        }
        return root;
    }
    TreeNode* convertBST1(TreeNode* root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        stack<TreeNode*> myStack;
        myStack.push(root);
        int sum = 0;
        while (!myStack.empty())
        {
            TreeNode* cur = myStack.top();
            myStack.pop();
            if (cur)
            {
                if (cur->left)
                {
                    myStack.push(cur->left);
                }
                myStack.push(cur);
                myStack.push(nullptr);
                if (cur->right)
                {
                    myStack.push(cur->right);
                }
            }
            else
            {
                cur = myStack.top();
                myStack.pop();
                sum += cur->val;
                cur->val = sum;
            }
        }
        return root;
    }
    void midOrder(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }
        if (root->left)
        {
            midOrder(root->left);
        }
        cout << root->val << " ";
        if (root->right)
        {
            midOrder(root->right);
        }
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
    sol.midOrder(sol.convertBST1(root));
    cout << endl;
    return 0;
}