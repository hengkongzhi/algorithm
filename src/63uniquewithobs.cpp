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

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        
        int m = obstacleGrid.size();
        if (m == 0)
        {
            return 0;
        }
        int n = obstacleGrid[0].size();
        vector<vector<int>> myVec(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    continue;
                }
                if (i == 0 && j == 0)
                {
                    myVec[0][0] = 1;
                    continue;
                }
                if (i - 1 < 0)
                {
                    myVec[i][j] = myVec[i][j - 1];
                    continue;
                }
                if (j - 1 < 0)
                {
                    myVec[i][j] = myVec[i - 1][j];
                    continue;
                }
                myVec[i][j] = myVec[i][j - 1] + myVec[i - 1][j];
            }
        }
        return myVec[m - 1][n - 1];
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> obstacleGrid{{0,0,0},{0,1,0},{0,0,0}};
    cout << sol.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}