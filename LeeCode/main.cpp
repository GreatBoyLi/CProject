#include <iostream>
#include "solution.h"
#include <bitset>

using namespace std;

int main(int argc, char *argv[])
{
    // vector<int> input = {1, 2, 3, 1};
    Solution solution;
    // cout << solution.rob_198(input) << endl;
    // cout << solution.countPrimes_204_1(10) << endl;
    // cout << solution.hammingWeight(11) << endl;
    // cout << solution.hammingDistance_1(1, 4) << endl;
    // cout << solution.reverseBits(43261596) << endl;
    /*
    int a[] = {1, 2, 3, 4, -1, -1, 5};
    TreeNode *root;
    initTree(root, a, 7);
    vector<vector<int>> re = solution.zigzagLevelOrder(root);
    for (auto i : re)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    */
    bitset<1> flag(0);
    flag = 1;
    cout << flag << endl;
    if (flag == 1)
        cout << "111111" << endl;
    else
        cout << "000000" << endl;
    cout << "x²" << endl;
    return 0;
}