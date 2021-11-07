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
    int findBottomLeftValue(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            return root->val;
        }
        queue<TreeNode*> myQ;
        myQ.push(root);
        bool isInit = false;
        int ret = 0;
        while (!myQ.empty())
        {
            int size = myQ.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode* cur = myQ.front();
                myQ.pop();
                if (cur->left)
                {
                    myQ.push(cur->left);
                    if (!isInit)
                    {
                        ret = cur->left->val;
                        isInit = true;
                    }
                }
                if (cur->right)
                {
                    myQ.push(cur->right);
                    if (!isInit)
                    {
                        ret = cur->right->val;
                        isInit = true;
                    }
                }
            }
            isInit = false;
        }
        return ret;
    }
    int maxdeep = -1;
    TreeNode* maxLeft = nullptr;
    void finddigui(TreeNode* root, int deep)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            if (deep > maxdeep)
            {
                maxdeep = deep;
                maxLeft = root;
            }
            return;
        }
        if (root->left)
        {
            finddigui(root->left, deep + 1);
        }
        if (root->right)
        {
            finddigui(root->right, deep + 1);
        }

    }
    int findBottomLeftValue1(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        finddigui(root, 0);
        return maxLeft->val;
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
    cout << sol.findBottomLeftValue1(root) << endl;
    return 0;
}