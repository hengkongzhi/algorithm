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
    vector<vector<int>> retV;
    void findPath(TreeNode* root, int target, vector<int>& myV)
    {
        if (!root->left && !root->right && target == 0)
        {
            retV.push_back(myV);
            return;
        }
        if (root->left)
        {
            myV.push_back(root->left->val);
            target -= root->left->val;
            findPath(root->left, target, myV);
            target += root->left->val;
            myV.pop_back();
        }
        if (root->right)
        {
            myV.push_back(root->right->val);
            target -= root->right->val;
            findPath(root->right, target, myV);
            target += root->right->val;
            myV.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        if (root == nullptr)
        {
            return retV;
        }
        vector<int> tmp;
        tmp.push_back(root->val);
        findPath(root, targetSum - root->val, tmp);
        return retV;
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

};
int main()
{
    Solution sol;
    TreeNode* root = new TreeNode(1);
    TreeNode* f1 = new TreeNode(2);
    TreeNode* f2 = new TreeNode(3);
    TreeNode* f4 = new TreeNode(6);
    TreeNode* f6 = new TreeNode(5);
    root->left = f1;
    root->right = f2;
    f1->left = f4;
    f2->right = f6;
    sol.printVec(sol.pathSum(root, 9));
    return 0;
}