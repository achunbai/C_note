//
//  1285：最大上升子序列和.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/2/19.
//

/*
 1285：最大上升子序列和

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 19246     通过数: 10592
 【题目描述】
 一个数的序列bi
 ，当b1<b2<...<bS
 的时候，我们称这个序列是上升的。对于给定的一个序列(a1,a2,...,aN)
 ，我们可以得到一些上升的子序列(ai1,ai2,...,aiK)
 ，这里1<=i1<i2<...<iK<=N
 。比如，对于序列(1,7,3,5,9,4,8)，有它的一些上升子序列，如(1,7),(3,4,8)等等。这些子序列中和最大为18，为子序列(1,3,5,9)的和。

 你的任务，就是对于给定的序列，求出最大上升子序列和。注意，最长的上升子序列的和不一定是最大的，比如序列(100,1,2,3)的最大上升子序列和为100，而最长上升子序列为(1,2,3)。

 【输入】
 输入的第一行是序列的长度N(1<=N<=1000)。第二行给出序列中的N个整数，这些整数的取值范围都在0到10000(可能重复)。

 【输出】
 最大上升子序列和。

 【输入样例】
 7
 1 7 3 5 9 4 8
 【输出样例】
 18
 */

// #include <bits/stdc++.h>
#include <iostream>
#include <climits>

using namespace std;

/*
 本题要求最大的子序列和，最长的并不一定是最大的，所以注意不是求长度
 
 状态
    dp[i]表示从起点开始到第i个点的最长上升子序列和
 状态转移方程
    if(a[i] > a[j]) dp[i] = max(dp[i], dp[j] + a[i])
 */
const int N = 1e3 + 10;

int a[N], dp[N], preIdx[N];

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    // 输入数据+初始化
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = a[i];
    }
    
    // 决策，找到从起点到i点为止最大的上升子序列和
    for(int i = 1; i <= n; i++)
        for(int j = 1; j < i; j++)
            if(a[i] > a[j])
                dp[i] = max(dp[i], dp[j] + a[i]);
    
    // 遍历，找到最终的全局最大值
    int ans = INT_MIN;
    for(int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}
