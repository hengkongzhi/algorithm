#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> arret;
        int i = 0;
        int j = 0;
        int h0 = 0;
        int s0 = 0;
        int hn = n - 1;
        int sn = n - 1;
        bool right = true;
        bool down = false;
        bool left = false;
        bool up = false;
        //题目限定了n小于等于20
        int arr[20][20] = {0};
        for (int index = 1; index <= n * n; index++)
        {
            arr[i][j] = index;
            if (index == n * n)
            {
                break;
            }
            if (right)
            {
                if (j + 1 > sn)
                {
                    h0++;
                    right = false;
                    down = true;
                    index--;
                    continue;
                }
                else
                {
                    j++;
                }
            }
            if (down)
            {
                if (i + 1 > hn)
                {
                    sn--;
                    down = false;
                    left = true;
                    index--;
                    continue;
                }
                else
                {
                    i++;
                }
            }
            if (left)
            {
                if (j - 1 < s0)
                {
                    hn--;
                    left = false;
                    up = true;
                    index--;
                    continue;
                }
                else
                {
                    j--;
                }
            }

            if (up)
            {
                if (i - 1 < h0)
                {
                    s0++;
                    up = false;
                    right = true;
                    index--;
                    continue;
                }
                else
                {
                    i--;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            vector<int> tmp;
            for (int j = 0; j < n; j++)
            {
                
                tmp.push_back(arr[i][j]);
            }
            arret.push_back(tmp);
        }
        return arret;
    }
};
int main()
{
    Solution m;
    int n = 4;
    vector<vector<int>> arr = m.generateMatrix(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}