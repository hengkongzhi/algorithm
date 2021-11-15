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
    TreeNode* pre = nullptr;
    int min = INT32_MAX;
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
        if (pre)
        {
            int temp = abs(root->val - pre->val);
            if (temp < min)
            {
                min = temp;
            }
            pre = root;
        }
        else
        {
            pre = root;
        }
        if (root->right)
        {
            midOrder(root->right);
        }
    }
    int getMinimumDifference(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        midOrder(root);
        return min;

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

    int min = sol.getMinimumDifference(root);
    cout << "The diff min is:" << min << endl;
    return 0;
}