#include "solution.h"
#include <math.h>
#include <iostream>
#include <bitset>
#include <stack>
#include <queue>

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
    dp[0][0] = 0;       // 第i个房子不偷
    dp[0][1] = nums[0]; // 第i个房子偷
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
    while (n > 1)
    {
        if (isPrime(n))
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
    while (s > 1)
    {
        if (n % s == 0)
            return 0;
        s--;
    }
    return 1;
}

int Solution::countPrimes_204_1(int n)
{
    vector<int> isPrime(n, 1);
    int ans = 0;
    for (int i = 2; i < n; ++i)
    {
        if (isPrime[i])
        {
            ans += 1;
            if ((long long)i * i < n)
            {
                for (int j = i * i; j < n; j += i)
                {
                    isPrime[j] = 0;
                }
            }
        }
    }
    return ans;
}

int Solution::hammingWeight(uint32_t n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (n & (1 << i))
            count++;
    }
    return count;
}

int Solution::hammingDistance(int x, int y)
{
    int count = 0;
    int z = x ^ y;
    for (int i = 0; i < 32; i++)
    {
        if (z & (1 << i))
            count++;
    }
    return count;
}

int Solution::hammingDistance_1(int x, int y)
{
    bitset<32> bit_x(x), bit_y(y);
    return (bit_x ^ bit_y).count();
}

int Solution::reverseBits(uint32_t n)
{
    bitset<32> bit_n(n);
    bitset<1> a;
    for (int i = 0; i < 16; i++)
    {
        a[0] = bit_n[i];
        bit_n[i] = bit_n[31 - i];
        bit_n[31 - i] = a[0];
    }
    return bit_n.to_ulong();
}

vector<vector<int>> Solution::generate(int numRows)
{
    vector<vector<int>> result;
    for (int i = 0; i < numRows; i++)
    {
        vector<int> temp;
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                temp.push_back(1);
            }
            else
            {
                temp.push_back(result[i - 1][j - 1] + result[i - 1][j]);
            }
        }
        result.push_back(temp);
    }
    return result;
}

bool Solution::isValid(string s)
{
    stack<char> st;
    for (auto c : s)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            if (st.empty() || st.top() != '(')
                return false;
            st.pop();
        }
        else if (c == ']')
        {
            if (st.empty() || st.top() != '[')
                return false;
            st.pop();
        }
        else if (c == '}')
        {
            if (st.empty() || st.top() != '{')
                return false;
            st.pop();
        }
    }
    if (!st.empty())
        return false;
    return true;
}

vector<int> Solution::inorderTraversal(TreeNode *p)
{
    vector<int> result;
    stack<TreeNode *> st;
    while (p != nullptr || !st.empty())
    {
        while (p != nullptr)
        {
            st.push(p);
            p = p->left;
        }
        p = st.top();
        st.pop();
        result.push_back(p->val);
        p = p->right;
    }
    return result;
}

vector<vector<int>> Solution::zigzagLevelOrder(TreeNode *root)
{
    stack<TreeNode *> a;
    stack<TreeNode *> b;
    vector<vector<int>> result;
    if (root == nullptr)
        return result;
    bool flag = true;
    b.push(root);
    while (!b.empty() || !a.empty())
    {
        if (flag)
        {
            flag = false;
            vector<int> temp;
            while (!b.empty())
            {
                TreeNode *node = b.top();
                if (node->left != nullptr)
                    a.push(node->left);
                if (node->right != nullptr)
                    a.push(node->right);
                temp.push_back(node->val);
                b.pop();
            }
            result.push_back(temp);
        }
        else
        {
            flag = true;
            vector<int> temp;
            while (!a.empty())
            {
                TreeNode *node = a.top();
                if (node->right != nullptr)
                    b.push(node->right);
                if (node->left != nullptr)
                    b.push(node->left);
                temp.push_back(node->val);
                a.pop();
            }
            result.push_back(temp);
        }
    }
    return result;
}