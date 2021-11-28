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
    TreeNode* sortedArrayToBST1(vector<int>& nums)
    {
        if (nums.size() == 0)
        {
            return nullptr;
        }
        queue<TreeNode*> myQ;
        queue<int> myLeft;
        queue<int> myRight;
        TreeNode* root = new TreeNode(0);
        myQ.push(root);
        int left = 0;
        int right = nums.size() - 1;
        myLeft.push(left);
        myRight.push(right);
        while (!myQ.empty())
        {
            TreeNode* cur = myQ.front();
            myQ.pop();
            left = myLeft.front(); myLeft.pop();
            right = myRight.front(); myRight.pop();
            int mid = (left + right) / 2;
            cur->val = nums[mid];
            if (mid - 1 >= left)
            {
                int left1 = left;
                int right1 = mid - 1;
                cur->left = new TreeNode(0);
                myQ.push(cur->left);
                myLeft.push(left1);
                myRight.push(right1);
            }
            if (mid + 1 <= right)
            {
                int left1 = mid + 1;
                int right1 = right;
                cur->right = new TreeNode(0);
                myQ.push(cur->right);
                myLeft.push(left1);
                myRight.push(right1);
            }
        }
        return root;

    }
    TreeNode* toBst(vector<int>& nums, int low, int high)
    {
        if (low > high)
        {
            return nullptr;
        }
        int mid = (low + high) / 2;
        TreeNode* cur = new TreeNode(nums[mid]);
        cur->left = toBst(nums, low, mid - 1);
        cur->right = toBst(nums, mid + 1, high);
        return cur;
        
    }
    TreeNode* sortedArrayToBST2(vector<int>& nums)
    {
        if (nums.size() == 0)
        {
            return nullptr;
        }
        return toBst(nums, 0, nums.size() - 1);
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
    sol.midOrder(sol.sortedArrayToBST2(nums));
    cout << endl;
    return 0;
}