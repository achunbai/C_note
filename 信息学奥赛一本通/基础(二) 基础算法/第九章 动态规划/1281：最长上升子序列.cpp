//
//  1281：最长上升子序列.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/2/19.
//

/*
 1281：最长上升子序列

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 33592     通过数: 17925
 【题目描述】
 一个数的序列bi
 ，当b1<b2<...<bS
 的时候，我们称这个序列是上升的。对于给定的一个序列(a1,a2,...,aN)
 ，我们可以得到一些上升的子序列(ai1,ai2,...,aiK)
 ，这里1≤i1<i2<...<iK≤N
 。比如，对于序列(1,7,3,5,9,4,8)，有它的一些上升子序列，如(1,7),(3,4,8)等等。这些子序列中最长的长度是4，比如子序列(1,3,5,8)。

 你的任务，就是对于给定的序列，求出最长上升子序列的长度。

 【输入】
 输入的第一行是序列的长度N(1≤N≤1000)。第二行给出序列中的N个整数，这些整数的取值范围都在0到10000。

 【输出】
 最长上升子序列的长度。

 【输入样例】
 7
 1 7 3 5 9 4 8
 【输出样例】
 4
 */

// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
 最长上升子序列-LIS
    1. 状态
        dp[i] 表示以第一个元素作为结尾的最长上升子序列长度
    2. 状态转移方程
        if(a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1)
 
 边界：
    dp[i]默认全部为1，因为仅包含自身长度为1
 
 a  1   2   3   4   5   6   7
    1   7   3   5   9   4   8
 
 dp 1   2   3   4   5   6   7
    1   2   2   3   4   3   4
    0   1   1   3   4   3   4 <- 从dp几转移
只有当前一个元素不大于当前元素的时候才能走转移
 */

const int N = 1e3 + 10;

int a[N], dp[N];

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = 1;
    }
    
    // 定义输出的答案
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        // 使用j遍历第i个元素之前的所有元素
        for(int j = 1; j < i; j++)
        {
            // 判断两者是否构成上升关系
            if(a[j] < a[i])
            {
                // 如果构成上升关系取最大值
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    
    cout << ans << endl;
    return 0;
}
