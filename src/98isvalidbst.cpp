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
    TreeNode* cur = nullptr;
    bool isValidBST(TreeNode* root)
    {
        if (root == nullptr)
        {
            return true;
        }
        bool leftT = isValidBST(root->left);
        if (cur && cur->val >= root->val)
        {
            return false;
        }
        cur = root;
        bool rightT = isValidBST(root->right);
        return leftT && rightT;
    }
    bool checkVec(vector<int>& myV)
    {
        for (int i = 0; i < myV.size(); i++)
        {
            if (i + 1 < myV.size() && myV[i] >= myV[i + 1])
            {
                return false;
            }
        }
        return true;
    }
    bool isValidBST1(TreeNode* root)
    {
        if (root == nullptr)
        {
            return false;
        }
        vector<int> myV;
        stack<TreeNode*> myS;
        myS.push(root);
        while (!myS.empty())
        {
            TreeNode* cur = myS.top();
            if (cur)
            {
                myS.pop();
                if (cur->right)
                {
                    myS.push(cur->right);
                }
                myS.push(cur);
                myS.push(nullptr);
                if (cur->left)
                {
                    myS.push(cur->left);
                }
            }
            else
            {
                myS.pop();
                myV.push_back(myS.top()->val);
                myS.pop();
            }
        }
        return checkVec(myV);
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

    bool cur = sol.isValidBST(root);
    cout << (cur ? "TRUE" : "FALSE") << endl;
    return 0;
}