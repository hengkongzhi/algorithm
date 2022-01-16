#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <stdlib.h>
#include <math.h>
#include <sstream>
#include <list>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    int minCameraCover(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        queue<TreeNode*> myQ;
        int level = 0;
        myQ.push(root);
        level++;
        map<int, int> myMap;
        int sum = 0;
        while (!myQ.empty())
        {
            int nums = myQ.size();
            myMap[level++] = nums;
            sum += nums;
            for (int i = 0; i < nums; i++)
            {
                TreeNode* cur = myQ.front();
                myQ.pop();
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
        level--;
        int ret = 0;
        if (level == 1 || level == 2)
        {
            return 1;
        }
        if (sum == 5)
        {
            return 2;
        }
        level--;
        for (; level >= 0; level -= 3)
        {
            if (level == 0)
            {
                level = 1;
            }
            ret += myMap[level];
        }
        return ret;
    }
};
int main()
{
    Solution sol;
    TreeNode* root = new TreeNode(0);
    TreeNode* f1 = new TreeNode(0);
    TreeNode* f2 = new TreeNode(0);
    TreeNode* f3 = new TreeNode(0);
    TreeNode* f4 = new TreeNode(0);
    root->left = f1;
    f1->left = f2;
    f2->left = f3;
    f3->right = f4;
    cout << sol.minCameraCover(root) << endl;
    return 0;
}