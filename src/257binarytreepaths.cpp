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
    void retVec(vector<int>& tmpV, vector<string>& myV)
    {
        ostringstream str;
        for (int i = 0; i < tmpV.size(); i++)
        {
            str << tmpV[i];
            if (i != tmpV.size() - 1)
            {
                str << "->";
            }
        }
        myV.push_back(str.str());
    }
    vector<string> binaryTreePaths(TreeNode* root)
    {
        stack<TreeNode*> mySt;
        vector<string> myV;
        vector<int> tmpV;
        if (root == nullptr)
        {
            return myV;
        }

        TreeNode* cur = root;
        mySt.push(cur);
        tmpV.push_back(cur->val);
        while (!mySt.empty())
        {
            while (cur->left && cur->left->val != -101)
            {
                mySt.push(cur->left);
                tmpV.push_back(cur->left->val);
                cur = cur->left;
            }
            if (cur->right && cur->right->val != -101)
            {
                mySt.push(cur->right);
                tmpV.push_back(cur->right->val);
                cur = cur->right;
            }
            else
            {
                cur = mySt.top();
                cur->val = -101;
                mySt.pop();
                if (cur->left == nullptr && cur->right == nullptr)
                {
                    retVec(tmpV, myV);
                }
                tmpV.pop_back();
                if (!mySt.empty())
                {
                    cur = mySt.top();
                }
                
            }
        }
        return myV;

    }
    void printMyStringVec(const vector<string>& myV)
    {
        for (auto val : myV)
        {
            cout << val << endl;
        }
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
    f4->right = f6;
    sol.printMyStringVec(sol.binaryTreePaths(root));
    return 0;
}