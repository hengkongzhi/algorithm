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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
    {
        TreeNode* cur;
        if (root1 == nullptr && root2 != nullptr)
        {
            return root2;
        }
        else if (root1 != nullptr && root2 == nullptr)
        {
            return root1;
        }
        else if (root1 == nullptr && root2 == nullptr)
        {
            return nullptr;
        }
        else
        {
            cur = new TreeNode(root1->val + root2->val);
        }
        cur->left = mergeTrees(root1->left, root2->left);
        cur->right = mergeTrees(root1->right, root2->right);
        return cur;
    }
    TreeNode* mergeTrees1(TreeNode* root1, TreeNode* root2)
    {
        if (root1 == nullptr)
        {
            return root2;
        }
        if (root2 == nullptr)
        {
            return root1;
        }
        queue<TreeNode*> myQ;
        myQ.push(root1);
        myQ.push(root2);
        while (!myQ.empty())
        {
            TreeNode* cur1 = myQ.front();
            myQ.pop();
            TreeNode* cur2 = myQ.front();
            myQ.pop();
            cur2->val += cur1->val;
            if (cur1->left && cur2->left)
            {
                myQ.push(cur1->left);
                myQ.push(cur2->left);
            }
            if (cur1->right && cur2->right)
            {
                myQ.push(cur1->right);
                myQ.push(cur2->right);
            }
            if (cur2->left == nullptr && cur1->left)
            {
                cur2->left = cur1->left;
            }
            if (cur2->right == nullptr && cur1->right)
            {
                cur2->right = cur1->right;
            }
        }
        return root2;
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
    TreeNode* root = new TreeNode(1);
    TreeNode* f1 = new TreeNode(2);
    TreeNode* f2 = new TreeNode(3);
    TreeNode* f4 = new TreeNode(4);
    TreeNode* f6 = new TreeNode(5);
    root->left = f1;
    root->right = f2;
    f1->left = f4;
    f2->right = f6;

    TreeNode* root1 = new TreeNode(2);
    TreeNode* f11 = new TreeNode(3);
    TreeNode* f21 = new TreeNode(4);
    TreeNode* f41 = new TreeNode(5);
    TreeNode* f61 = new TreeNode(6);
    root1->left = f11;
    root1->right = f21;
    f11->left = f41;
    f21->right = f61;    
    TreeNode* cur = sol.mergeTrees1(root, root1);
    sol.preOrderPrint(cur);
    return 0;
}