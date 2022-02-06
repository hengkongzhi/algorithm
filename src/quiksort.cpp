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
    int partition(vector<int>& myV, int low, int high)
    {
        int val = myV[low];
        while (low < high)
        {
            while (myV[high] >= val && low < high)
            {
                high--;
            }
            myV[low] = myV[high];
            while (myV[low] <= val && low < high)
            {
                low++;
            }
            myV[high] = myV[low];
        }
        myV[low] = val;
        return low;
    }
    void initSort(vector<int>& myV, int low, int high)
    {
        if (low < high)
        {
            int index = partition(myV, low, high);
            initSort(myV, low, index - 1);
            initSort(myV, index + 1, high);
        }
    }
    void quikSort(vector<int>& myV)
    {
        initSort(myV, 0, myV.size() - 1);
    }
    void vecPrint(vector<int>& myV)
    {
        for (auto val : myV)
        {
            cout << val << " ";
        }
        cout << endl;
    }
};
int main()
{
    Solution sol;
    vector<int> myV{200, 123, -100, 1, 175, 18, 23, -20, 100};
    sol.vecPrint(myV);
    sol.quikSort(myV);
    sol.vecPrint(myV);
    return 0;
}