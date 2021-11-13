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
    TreeNode* searchBST(TreeNode* root, int val)
    {
        if (root == nullptr)
        {
            return root;
        }
        if (root->val == val)
        {
            return root;
        }
        if (root->val > val)
        {
            return searchBST(root->left, val);
        }
        if (root->val < val)
        {
            return searchBST(root->right, val);
        }
    }
    TreeNode* searchBST1(TreeNode* root, int val)
    {
        while (root != nullptr)
        {
            if (root->val > val)
            {
                root = root->left;
            }
            else if (root->val < val)
            {
                root = root->right;
            }
            else
            {
                return root;
            }
        }
        return nullptr;
    }
    void printVec(const vector<vector<int>>& myV)
    {
        for (auto& vec : myV)
        {
            for (auto& val : vec)
            {
                cout << val << " ";
            }
            cout << endl;
        }
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

    TreeNode* cur = sol.searchBST1(root, 2);
    sol.preOrderPrint(cur);
    return 0;
}