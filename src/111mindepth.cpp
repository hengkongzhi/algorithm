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
    int minDepth(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        if (root->left && root->right)
        {
            int depLeft = minDepth(root->left);
            int depRight = minDepth(root->right);
            return (depRight < depLeft ? (depRight + 1) : (depLeft + 1));
        }
        if (!root->left && root->right)
        {
            return minDepth(root->right) + 1;
        }
        if (root->left && !root->right)
        {
            return minDepth(root->left) + 1;
        }
        return 1;
    }
    int minDepth1(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        queue<TreeNode*> myQ;
        myQ.push(root);
        int depth = 0;
        while (!myQ.empty())
        {
            depth++;
            int size = myQ.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode* cur = myQ.front();
                myQ.pop();
                if (!cur->left && !cur->right)
                {
                    return depth;
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
        }
        return depth;
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
    f1->right = f4;
    f2->right = f6;
    cout << sol.minDepth1(root) << endl;
    return 0;
}