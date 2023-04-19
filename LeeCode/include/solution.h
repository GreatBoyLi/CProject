#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>

using namespace std;

class Solution
{
public:
    int rob_198(vector<int> &nums);

    int countPrimes_204_1(int n);

    int countPrimes_204(int n);
    // 判断是否为质数
    int isPrime(int n);
    // 191. 位1的个数
    int hammingWeight(uint32_t);
    // 461. 汉明距离
    int hammingDistance(int x, int y);
    // 461. 汉明距离
    int hammingDistance_1(int x, int y);
};

#endif