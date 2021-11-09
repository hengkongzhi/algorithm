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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        int len = postorder.size();
        if (len == 0)
        {
            return nullptr;
        }
        int val = postorder[len - 1];
        TreeNode* root = new TreeNode(val);
        auto iter = find(inorder.begin(), inorder.end(), val);
        vector<int> myInorderLeft(inorder.begin(), iter);
        vector<int> myInorderRight(iter + 1, inorder.end());
        int sizeR = myInorderRight.size();
        vector<int> myPostorderLeft(postorder.begin(), postorder.end() - 1 - sizeR);
        vector<int> myPostorderRight(postorder.end() - 1 - sizeR, postorder.end() - 1);

        root->left = buildTree(myInorderLeft, myPostorderLeft);
        root->right = buildTree(myInorderRight, myPostorderRight);
        return root;
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
    vector<int> inorder{9};
    vector<int> postorder{9};
    TreeNode* cur = sol.buildTree(inorder, postorder);
    sol.preOrderPrint(cur);
    return 0;
}