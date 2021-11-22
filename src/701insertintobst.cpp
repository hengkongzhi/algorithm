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
    TreeNode* insertIntoBST1(TreeNode* root, int val)
    {
        if (root == nullptr)
        {
            root = new TreeNode(val);
            return root;
        }
        if (root->val > val)
        {
            root->left = insertIntoBST1(root->left, val);
        }
        if (root->val < val)
        {
            root->right = insertIntoBST1(root->right, val);
        }
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val)
    {
        TreeNode* pVal = new TreeNode(val);
        if (root == nullptr)
        {
            return pVal;
        }
        TreeNode* cur = root;
        while (cur)
        {
            if (val > cur->val)
            {
                if (cur->right)
                {
                    cur = cur->right;
                }
                else
                {
                    cur->right = pVal;
                    break;
                }
            }
            if (val < cur->val)
            {
                if (cur->left)
                {
                    cur = cur->left;
                }
                else
                {
                    cur->left = pVal;
                    break;
                } 
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
    sol.midOrder(sol.insertIntoBST1(root, 0));
    cout << endl;
    return 0;
}