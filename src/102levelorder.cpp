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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> myVecArr;
        queue<TreeNode*> myQ;
        if (root == nullptr)
        {
            return myVecArr;
        }
        myQ.push(root);
        TreeNode* cur;
        int count = 0;
        vector<int> tmp;
        int n = 1;
        while (!myQ.empty())
        {
            cur = myQ.front();
            
            if (cur != nullptr)
            {
                myQ.push(cur->left);
                myQ.push(cur->right);
                tmp.push_back(cur->val);
            }
            else
            {
                myQ.push(nullptr);
                myQ.push(nullptr);
            }
            myQ.pop();
            count++;
            if (count == pow(2, n) - 1)
            {
                if (tmp.empty())
                {
                    break;
                }
                myVecArr.push_back(tmp);
                tmp.clear();
                n++;
            }
        }
        return myVecArr;
    }
    vector<vector<int>> levelOrder1(TreeNode* root)
    {
        vector<vector<int>> myVecArr;
        queue<TreeNode*> myQ;
        if (root == nullptr)
        {
            return myVecArr;
        }
        myQ.push(root);
        TreeNode* cur;
        TreeNode* last;
        vector<int> tmp;
        last = root;
        while (!myQ.empty())
        {
            cur = myQ.front();
            tmp.push_back(cur->val);
            if (cur->left)
            {
                myQ.push(cur->left);
            }
            if (cur->right)
            {
                myQ.push(cur->right);
            }
            myQ.pop();
            if (cur == last)
            {
                if (cur->left && cur->right)
                {
                    last = cur->right;
                }
                if (cur->left && !cur->right)
                {
                    last = cur->left;
                }
                if (!cur->left && cur->right)
                {
                    last = cur->right;
                }
                myVecArr.push_back(tmp);
                tmp.clear();
            }
        }
        return myVecArr;
    }
    vector<vector<int>> levelOrder2(TreeNode* root)
    {
        vector<vector<int>> myVecArr;
        queue<TreeNode*> myQ;
        if (root == nullptr)
        {
            return myVecArr;
        }
        myQ.push(root);
        vector<int> tmp;
        TreeNode* cur;
        while (!myQ.empty())
        {
            int size = myQ.size();
            for (int i = 0; i < size; i++)
            {
                cur = myQ.front();
                myQ.pop();
                tmp.push_back(cur->val);
                if (cur->left)
                {
                    myQ.push(cur->left);
                }
                if (cur->right)
                {
                    myQ.push(cur->right);
                }
            }
            myVecArr.push_back(tmp);
            tmp.clear();
        }
        return myVecArr;
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
    sol.printVecArr(sol.levelOrder2(root));
    return 0;
}