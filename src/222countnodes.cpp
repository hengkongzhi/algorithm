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
    int countNodes(TreeNode* root)
    {
        stack<TreeNode*> myStack;
        if (root == nullptr)
        {
            return 0;
        }
        int count = 0;
        myStack.push(root);
        count++;
        TreeNode* cur;
        while (!myStack.empty())
        {
            cur = myStack.top();
            myStack.pop();

            if (cur->right)
            {
                myStack.push(cur->right);
                count++;
            }
            if (cur->left)
            {
                myStack.push(cur->left);
                count++;
            }
        }
        return count;
    }
    int countNodes1(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        queue<TreeNode*> myQ;
        myQ.push(root);
        int depth = 0;
        int count = 0;
        while (!myQ.empty())
        {
            depth++;
            int size = myQ.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode* cur = myQ.front();
                myQ.pop();
                if (!cur->left && !cur->right)
                {
                    count = pow(2, depth) - 1 + i * 2;
                    return count;
                }
                if (cur->left && !cur->right)
                {
                    count = pow(2, depth) + i * 2;
                    return count;
                }
                if (cur->left)
                {
                    myQ.push(cur->left);
                }
                if (cur->right)
                {
                    myQ.push(cur->right);
                }
            }
        }
        return count;
    }

    int countNodes2(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int leftNodNum = countNodes2(root->left);
        int rightNodNum = countNodes2(root->right);
        return leftNodNum + rightNodNum + 1;
    }
    int countNodes3(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        TreeNode* leftNode = root->left;
        TreeNode* rightNode = root->right;
        int leftDep = 0, rightDep = 0;
        while (leftNode)
        {
            leftDep++;
            leftNode = leftNode->left;
        }
        while (rightNode)
        {
            rightDep++;
            rightNode = rightNode->right;
        }
        if (leftDep == rightDep)
        {
            return (2 << leftDep) - 1;
        }
        return countNodes3(root->left) + countNodes3(root->right) + 1;
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
    f1->left = f4;
    f1->right = f6;
    cout << sol.countNodes3(root) << endl;
    return 0;
}