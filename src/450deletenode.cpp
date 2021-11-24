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
    TreeNode* findLastLeft(TreeNode* cur)
    {
        while (cur->left)
        {
            cur = cur->left;
        }
        return cur;
    }
    enum Tag
    {
        LEFT,
        RIGHT,
        UNKNOWN
    };
    TreeNode* deleteNode1(TreeNode* root, int key)
    {
        if (root == nullptr)
        {
            return root;
        }
        if (root->val == key)
        {
            if (root->left == nullptr)
            {
                return root->right;
            }
            if (root->right == nullptr)
            {
                return root->left;
            }
            if (root->left && root->right)
            {
                TreeNode* cur = root->right;
                while (cur->left)
                {
                    cur = cur->left;
                }
                cur->left = root->left;
                return root->right;
            }
        }
        root->left = deleteNode1(root->left, key);
        root->right = deleteNode1(root->right, key);
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if (root == nullptr)
        {
            return root;
        }
        if (root->val == key)
        {
            TreeNode* right = root->right;
            TreeNode* left = root->left;
            if (right)
            {
                TreeNode* lastLeft = findLastLeft(right);
                lastLeft->left = left;
                return right;
            }
            else
            {
                return left;
            }
        }
        pair<TreeNode*, Tag> pre;
        pre.first = nullptr;
        pre.second = UNKNOWN;
        TreeNode* cur = root;
        while (cur)
        {
            if (cur->val == key)
            {
                if (cur->right)
                {
                    TreeNode* lastLeft = findLastLeft(cur->right);
                    lastLeft->left = cur->left;
                    if (pre.second == LEFT)
                    {
                        pre.first->left = cur->right;
                    }
                    else
                    {
                        pre.first->right = cur->right;
                    }
                }
                else
                {
                    if (pre.second == LEFT)
                    {
                        pre.first->left = cur->left;
                    }
                    else
                    {
                        pre.first->right = cur->left;
                    }
                }
                break;
            }
            else
            {
                if (cur->val > key)
                {
                    pre.first = cur;
                    pre.second = LEFT;
                    cur = cur->left;
                }
                else
                {
                    pre.first = cur;
                    pre.second = RIGHT;
                    cur = cur->right;                   
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
    sol.midOrder(sol.deleteNode1(root, 2));
    cout << endl;
    return 0;
}