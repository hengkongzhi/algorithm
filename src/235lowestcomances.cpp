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
    bool findNode(TreeNode* root, TreeNode* f)
    {
        if (root == nullptr)
        {
            return false;
        }
        bool leftF = false;
        bool rightF = false;
        if (root->left)
        {
            leftF = findNode(root->left, f);
        }
        if (root->val == f->val)
        {
            return true;
        }
        if (leftF)
        {
            return leftF;
        }
        if (root->right)
        {
            rightF = findNode(root->right, f);
        }
        return rightF;

    }
    vector<TreeNode*> myV;
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
        myV.push_back(root);
        if (root->right)
        {
            midOrder(root->right);
        }
    }
    int findIter(TreeNode* f)
    {
        for (int i = 0; i < myV.size(); i++)
        {
            if (myV[i]->val == f->val)
            {
                return i;
            }
        }
        return -1;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        midOrder(root);
        int pIndex = findIter(p);
        int qIndex = findIter(q);
        if (pIndex < qIndex)
        {
            for (int i = pIndex; i <= qIndex; i++)
            {
                if (findNode(myV[i], p) && findNode(myV[i], q))
                {
                    return myV[i];
                }
            }
        }
        else
        {
            for (int i = qIndex; i <= pIndex; i++)
            {
                if (findNode(myV[i], p) && findNode(myV[i], q))
                {
                    return myV[i];
                }
            }           
        }
        return nullptr;
    }
    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == nullptr || root == p || root == q)
        {
            return root;
        }
        TreeNode* leftA = lowestCommonAncestor1(root->left, p, q);
        TreeNode* rightA = lowestCommonAncestor1(root->right, p, q);
        if (leftA == nullptr && rightA)
        {
            return rightA;
        }
        if (rightA == nullptr && leftA)
        {
            return leftA;
        }
        if (leftA && rightA)
        {
            return root;
        }
        if (leftA == nullptr && rightA == nullptr)
        {
            return nullptr;
        }

    }
    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == nullptr)
        {
            return root;
        }
        if (root->val > p->val && root->val > q->val)
        {
            TreeNode* left = lowestCommonAncestor2(root->left, p, q);
            if (left)
            {
                return left;
            }
        }
        if (root->val < p->val && root->val < q->val)
        {
            TreeNode* right = lowestCommonAncestor2(root->right, p, q);
            if (right)
            {
                return right;
            }
        }
        return root;
    }
    TreeNode* lowestCommonAncestor3(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        while (root)
        {
            if (root->val > p->val && root->val > q->val)
            {
                root = root->left;
            }
            else if (root->val < p->val && root->val < q->val)
            {
                root = root->right;
            }
            else
            {
                return root;
            }
        }
        return nullptr;
    }
    void printVec(const vector<int>& myV)
    {
        for (auto& val : myV)
        {
            cout << val << " ";
        }
        cout << endl;
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
    cout << sol.lowestCommonAncestor2(root, f1, f6)->val << endl;
    return 0;
}