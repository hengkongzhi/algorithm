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
    int getDepth(TreeNode* root, bool* bFlag)
    {
        if (root == nullptr)
        {
            *bFlag = true;
            return 0;
        }
        bool flag = false;
        int leftDep = getDepth(root->left, &flag);
        if (flag == false)
        {
            *bFlag = false;
            return 0;
        }
        int rightDep = getDepth(root->right, &flag);
        if (flag == false)
        {
            *bFlag = false;
            return 0;
        }
        if (abs(leftDep - rightDep) > 1)
        {
            *bFlag = false;
        }
        else
        {
            *bFlag = true;
        }
        return (leftDep > rightDep ? leftDep + 1 : rightDep + 1);
    }
    bool isBalanced(TreeNode* root)
    {
        bool flag = false;
        getDepth(root, &flag);
        if (flag)
        {
            return true;
        }
        return false;
    }
    int depth(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left = depth(root->left);
        if (left == -1)
        {
            return -1;
        }
        int right = depth(root->right);
        if (right == -1)
        {
            return -1;
        }
        if (abs(left - right) > 1)
        {
            return -1;
        }
        else
        {
            return max(left, right) + 1;
        }
    }
    bool isBalanced1(TreeNode* root)
    {
        if (depth(root) == -1)
        {
            return false;
        }
        return true;
    }

};
int main()
{
    Solution sol;
    TreeNode* root = new TreeNode(1);
    TreeNode* f1 = new TreeNode(2);
    TreeNode* f2 = new TreeNode(2);
    TreeNode* f4 = new TreeNode(3);
    TreeNode* f6 = new TreeNode(3);
    root->left = f1;
    root->right = f2;
    f1->left = f4;
    f4->right = f6;
    cout << (sol.isBalanced1(root) ? "TRUE" : "FALSE") << endl;
    return 0;
}