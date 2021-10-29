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
    int maxDepth(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        queue<TreeNode*> myQ;
        myQ.push(root);
        int depth = 0;
        TreeNode* cur;
        while (!myQ.empty())
        {
            depth++;
            int size = myQ.size();
            for (int i = 0; i < size; i++)
            {
                cur = myQ.front();
                myQ.pop();
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
    int maxDepth1(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int leftDepth = maxDepth1(root->left);
        int rightDepth = maxDepth1(root->right);
        return (leftDepth > rightDepth ? (leftDepth + 1) : (rightDepth + 1));
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
    cout << sol.maxDepth1(root) << endl;
    return 0;
}