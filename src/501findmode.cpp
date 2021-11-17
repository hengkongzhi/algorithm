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
    struct compare
    {
        bool operator()(pair<int,int>& t1, pair<int,int>& t2)
        {
            return t1.second > t2.second;
        }
    };
    map<int, int> myMap;
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
        myMap[root->val]++;
        if (root->right)
        {
            midOrder(root->right);
        }
    }
    vector<int> findMode(TreeNode* root)
    {
        if (root == nullptr)
        {
            return {};
        }
        vector<int> ret;
        midOrder(root);
        vector<pair<int, int>> myV(myMap.begin(), myMap.end());
        sort(myV.begin(), myV.end(), compare());
        auto iter = myV.begin();
        int pre = 0;
        for (; iter != myV.end(); iter++)
        {
            if (iter == myV.begin())
            {
                pre = iter->second;
                ret.push_back(iter->first);
                continue;
            }
            if (iter->second != pre)
            {
                break;
            }
            else
            {
                ret.push_back(iter->first);
            }
        }
        return ret;
    }
    TreeNode* pre = nullptr;
    vector<int> myV;
    int count;
    int maxCount = INT32_MIN;
    void midOrder1(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }
        if (root->left)
        {
            midOrder1(root->left);
        }
        if (pre == nullptr)
        {
            count = 1;
            pre = root;
        }
        else if (pre->val == root->val)
        {
            count += 1;
        }
        else
        {   
            if (count > maxCount)
            {
                maxCount = count;
                myV.clear();
                myV.push_back(pre->val);
            }
            else if (count == maxCount)
            {
                myV.push_back(pre->val);
            }
            count = 1;
            pre = root;
        }
        
        if (root->right)
        {
            midOrder1(root->right);
        }
    }
    vector<int> findMode1(TreeNode* root)
    {
        if (root == nullptr)
        {
            return {};
        }
        midOrder1(root);
        if (count > maxCount)
        {
            maxCount = count;
            myV.clear();
            myV.push_back(pre->val);
        }
        else if (count == maxCount)
        {
            myV.push_back(pre->val);
        }
        return myV;
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
    TreeNode* f2 = new TreeNode(3);
    TreeNode* f4 = new TreeNode(1);
    TreeNode* f6 = new TreeNode(5);
    root->left = f1;
    root->right = f2;
    f1->left = f4;
    f2->right = f6;
    sol.printVec(sol.findMode1(root));
    return 0;
}