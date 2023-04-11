#include "solution.h"

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