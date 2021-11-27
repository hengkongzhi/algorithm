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
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        int size = nums.size();
        if (size == 0)
        {
            return nullptr;
        }
        int pos = size / 2;
        TreeNode* root = new TreeNode(nums[pos]);
        int i = pos;
        vector<int> tmp(nums.begin(), nums.begin() + i);
        root->left = sortedArrayToBST(tmp);
        int j = pos + 1;
        vector<int> tmp1(nums.begin() + j, nums.end());
        root->right = sortedArrayToBST(tmp1);
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
    vector<int> nums{-10,-3,0,5,9};
    sol.midOrder(sol.sortedArrayToBST(nums));
    cout << endl;
    return 0;
}