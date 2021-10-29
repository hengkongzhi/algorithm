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
    bool judSame(vector<TreeNode*>& myV)
    {
        for (int i = 0, j = myV.size() - 1; i < j; i++, j--)
        {
            if (myV[i] == nullptr)
            {
                if (myV[j] != nullptr)
                {
                    return false;
                }
            }
            else
            {
                if (myV[j] == nullptr)
                {
                    return false;
                }
                else
                {
                    if (myV[i]->val != myV[j]->val)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool isSymmetric(TreeNode* root)
    {
        vector<TreeNode*> myV;
        queue<TreeNode*> myQ;
        myQ.push(root);
        TreeNode* cur;
        while (!myQ.empty())
        {
            int size = myQ.size();
            for (int i = 0; i < size; i++)
            {
                cur = myQ.front();
                if (cur != nullptr)
                {
                    myQ.push(cur->left);
                    myQ.push(cur->right);
                    myV.push_back(cur->left);
                    myV.push_back(cur->right);
                }
                myQ.pop();
            }
            if (!judSame(myV))
            {
                return false;
            }
            myV.clear();
        }
        return true;
    }
    bool compare(TreeNode* leftNode, TreeNode* rightNode)
    {
        if (leftNode != nullptr && rightNode == nullptr)
        {
            return false;
        }
        else if (leftNode == nullptr && rightNode != nullptr)
        {
            return false;
        }
        else if (leftNode == nullptr && rightNode == nullptr)
        {
            return true;
        }
        else if (leftNode->val != rightNode->val)
        {
            return false;
        }
        return (compare(leftNode->left, rightNode->right) && compare(leftNode->right, rightNode->left));
    }
    bool isSymmetric1(TreeNode* root)
    {
        if (root == nullptr)
        {
            return true;
        }
        return compare(root->left, root->right);
    }
    bool isSymmetric2(TreeNode* root)
    {
        stack<TreeNode*> myStack1;
        stack<TreeNode*> myStack2;
        if (root == nullptr)
        {
            return true;
        }
        myStack1.push(root->left);
        myStack2.push(root->right);
        TreeNode *cur1, *cur2;

        while (!myStack2.empty() && !myStack1.empty())
        {
            cur1 = myStack1.top();
            cur2 = myStack2.top();
            if (cur1 == nullptr && cur2 != nullptr)
            {
                return false;
            }
            else if (cur2 == nullptr && cur1 != nullptr)
            {
                return false;
            }
            else if (cur2 == nullptr && cur1 == nullptr)
            {
                myStack2.pop();
                myStack1.pop();
                continue;
            }
            else if (cur1->val != cur2->val)
            {
                return false;
            }
            myStack2.pop();
            myStack1.pop();
            myStack1.push(cur1->left);
            myStack1.push(cur1->right);
            myStack2.push(cur2->right);
            myStack2.push(cur2->left);
        }
        return myStack1.empty() && myStack2.empty();
    }

    void printVecArr(const vector<vector<int>>& myVecArr)
    {
        for (auto myV : myVecArr)
        {
            for (auto value : myV)
            {
                cout << value << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    Solution sol;
    TreeNode* root = new TreeNode(1);
    TreeNode* f1 = new TreeNode(2);
    TreeNode* f2 = new TreeNode(2);
    TreeNode* f4 = new TreeNode(3);
    TreeNode* f6 = new TreeNode(3);
    root->left = f1;
    root->right = f2;
    f1->right = f4;
    f2->right = f6;
    cout << (sol.isSymmetric2(root) ? "TRUE" : "FALSE") << endl;
    return 0;
}