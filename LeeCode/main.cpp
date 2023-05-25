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
    
    int b[] = {1, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5};
    int n = 17;
    int mode = 0, multiplicity = 0;
    solution.Mode(b, mode, multiplicity, n);
    cout << mode << " " << multiplicity << endl;

    vector<int> a = {1, 2, 3, 4, 5};
    a.erase(a.begin());
    for (auto i : a)
    {
        cout << i << endl;
    }
    return 0;
}