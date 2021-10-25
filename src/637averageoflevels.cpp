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
    double calArrAverage(vector<int>& myV)
    {
        double sum = 0;
        for (auto vu : myV)
        {
            sum += vu;
        }
        return sum / myV.size();
    }
    vector<double> averageOfLevels(TreeNode* root)
    {
        queue<TreeNode*> myQ;
        vector<double> myV;
        if (root == nullptr)
        {
            return myV;
        }
        myQ.push(root);
        TreeNode* cur;
        vector<int> tmp;
        
        while (!myQ.empty())
        {
            int size = myQ.size();
            double sum = 0;
            for (int i = 0; i < size; i++)
            {
                cur = myQ.front();
                myQ.pop();
                sum += cur->val;
                if (cur->left)
                {
                    myQ.push(cur->left);
                }
                if (cur->right)
                {
                    myQ.push(cur->right);
                }
            }
            myV.push_back(sum / size);
        }
        return myV;
    }
    void printVec(const vector<double>& myV)
    {
        for (auto vu : myV)
        {
            cout << vu << " ";
        }
        cout << endl;
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
    sol.printVec(sol.averageOfLevels(root));
    return 0;
}