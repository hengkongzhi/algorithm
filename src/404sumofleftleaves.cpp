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
    void getVec(TreeNode* cur, bool isLeft, vector<int>& myV)
    {
        if (cur == nullptr)
        {
            return;
        }
        if (cur->left == nullptr && cur->right == nullptr && isLeft)
        {
            myV.push_back(cur->val);
        }
        if (cur->left)
        {
            getVec(cur->left, true, myV);
        }
        if (cur->right)
        {
            getVec(cur->right, false, myV);
        }
    }
    int sumOfLeftLeaves(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        vector<int> myV;
        getVec(root, false, myV);
        int sum = 0;
        for (auto& val : myV)
        {
            sum += val;
        }
        return sum;
    }
    int sumOfLeftLeaves1(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int sum = 0;
        stack<TreeNode*> myStack;
        myStack.push(root);
        while (!myStack.empty())
        {
            TreeNode* cur = myStack.top();
            myStack.pop();
            if (cur->left && !cur->left->left && !cur->left->right)
            {
                sum += cur->left->val;
            }
            if (cur->right)
            {
                myStack.push(cur->right);
            }
            if (cur->left)
            {
                myStack.push(cur->left);
            }
        }
        return sum;
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
    cout << sol.sumOfLeftLeaves1(root) << endl;
    return 0;
}