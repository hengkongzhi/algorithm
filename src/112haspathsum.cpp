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
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        if (root == nullptr)
        {
            return false;
        }
        targetSum -= root->val;
        if (root->left == nullptr && root->right == nullptr)
        {
            if (0 == targetSum)
            {
                return true;
            }
            return false;
        }
        if (root->left)
        {
            if (hasPathSum(root->left, targetSum))
            {
                return true;
            } 
        }
        if (root->right)
        {
            if (hasPathSum(root->right, targetSum))
            {
                return true;
            } 
        }
        return false;
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
    f2->right = f6;
    cout << (sol.hasPathSum(root, 8) ? "TRUE" : "FALSE") << endl;
    return 0;
}