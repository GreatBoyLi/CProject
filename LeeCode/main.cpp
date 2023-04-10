#include <iostream>
#include "solution.h"

using namespace std;

int main(int argc, char *argv[])
{
    vector<int> input = {1, 2, 3, 1};
    Solution solution;
    cout << solution.rob_198(input) << endl;
    return 0;
}