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
    int findMax(vector<int>& nums)
    {
        int max = INT32_MIN;
        int iter = 0; 
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > max)
            {
                max = nums[i];
                iter = i;
            }
        }
        return iter;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        int size = nums.size();
        if (size == 0)
        {
            return nullptr;
        }
        int iter = findMax(nums);
        vector<int> left(nums.begin(), nums.begin() + iter);
        vector<int> right(nums.begin() + iter + 1, nums.end());
        TreeNode* root = new TreeNode(nums[iter]);
        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);
        return root;
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
    vector<int> inorder{3,2,1,6,0,5};
    TreeNode* cur = sol.constructMaximumBinaryTree(inorder);
    sol.preOrderPrint(cur);
    return 0;
}