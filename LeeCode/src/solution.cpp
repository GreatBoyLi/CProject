#include "solution.h"
#include <math.h>
#include <iostream>

int Solution::rob_198(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    int length = nums.size();
    int **dp = new int *[length];
    for (int i = 0; i < length; i++)
    {
        dp[i] = new int[2];
    }
    dp[0][0] = 0;   // 第i个房子不偷
    dp[0][1] = nums[0];  // 第i个房子偷
    for (int i = 1; i < length; i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = dp[i - 1][0] + nums[i];
    }
    return max(dp[length - 1][0], dp[length - 1][1]);
}


int Solution::countPrimes_204(int n)
{
    int count = 0;
    while(n > 1){
        if(isPrime(n))
        {
            count++;
        }
        n--;
    }
    return count;
}


int Solution::isPrime(int n)
{
    int s = sqrt(n);
    while(s > 1)
    {
        if(n % s == 0)
            return 0;
        s--;
    }
    return 1;
}


int Solution::countPrimes_204_1(int n)
{
    vector<int> isPrime(n, 1);
    int ans = 0;
    for (int i = 2; i < n; ++i) {
        if (isPrime[i]) {
            ans += 1;
            if ((long long)i * i < n) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = 0;
                }
            }
        }
    }
    return ans;
}