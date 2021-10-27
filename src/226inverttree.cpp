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
    TreeNode* invertTree(TreeNode* root)
    {
        queue<TreeNode*> myQ;
        if (root == nullptr)
        {
            return root;
        }
        myQ.push(root);
        TreeNode* cur;
        TreeNode* tmp;
        while (!myQ.empty())
        {
            int size = myQ.size();
            for (int i = 0; i < size; i++)
            {
                cur = myQ.front();
                myQ.pop();
                if (cur != nullptr)
                {
                    tmp = cur->left;
                    cur->left = cur->right;
                    cur->right = tmp;
                    myQ.push(cur->left);
                    myQ.push(cur->right);
                }
            }
        }
        return root;
    }
    TreeNode* invertTree1(TreeNode* root)
    {
        if (root == nullptr)
        {
            return root;
        }
        invertTree1(root->left);
        invertTree1(root->right);
        swap(root->left, root->right);
        return root;
    }
    TreeNode* invertTree2(TreeNode* root)
    {
        stack<TreeNode*> myS;
        if (root == nullptr)
        {
            return root;
        }
        myS.push(root);
        TreeNode* head;
        while (!myS.empty())
        {
            head = myS.top();
            myS.pop();
            swap(head->left, head->right);
            if (head->left)
            {
                myS.push(head->left);
            }
            if (head->right)
            {
                myS.push(head->right);
            }
        }
        return root;
    }
    TreeNode* invertTree3(TreeNode* root)
    {
        stack<TreeNode*> myS;
        if (root == nullptr)
        {
            return root;
        }
        myS.push(root);
        TreeNode* head;
        while (!myS.empty())
        {
            head = myS.top();
            if (head)
            {
                myS.push(nullptr);
                if (head->right)
                {
                    myS.push(head->right);
                }
                if (head->left)
                {
                    myS.push(head->left);
                }

            }
            else
            {
                myS.pop();
                head = myS.top();
                myS.pop();
                swap(head->left, head->right);
            }
        }
        return root;
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
    TreeNode* root = new TreeNode(10);
    TreeNode* f1 = new TreeNode(8);
    TreeNode* f2 = new TreeNode(7);
    TreeNode* f3 = new TreeNode(5);
    TreeNode* f4 = new TreeNode(6);
    TreeNode* f5 = new TreeNode(3);
    TreeNode* f6 = new TreeNode(4);
    root->left = f1;
    root->right = f2;
    f1->left = f3;
    f1->right = f4;
    f2->left = f5;
    f2->right = f6;
    cout << root->left->val << endl;
    cout << sol.invertTree(root)->left->val << endl;
    return 0;
}