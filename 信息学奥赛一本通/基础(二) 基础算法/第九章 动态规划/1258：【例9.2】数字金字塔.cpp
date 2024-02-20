//
//  1258：【例9.2】数字金字塔.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/2/18.
//

/*
 1258：【例9.2】数字金字塔

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 44171     通过数: 26362
 【题目描述】
 观察下面的数字金字塔。写一个程序查找从最高点到底部任意处结束的路径，使路径经过数字的和最大。每一步可以从当前点走到左下方的点也可以到达右下方的点。



 在上面的样例中,从13
 到8
 到26
 到15
 到24
 的路径产生了最大的和86
 。

 【输入】
 第一个行包含R(1≤R≤1000)
 ，表示行的数目。

 后面每行为这个数字金字塔特定行包含的整数。

 所有的被供应的整数是非负的且不大于100
 。

 【输出】
 单独的一行，包含那个可能得到的最大的和。

 【输入样例】
 5
 13
 11 8
 12 7  26
 6  14 15 8
 12 7  13 24 11
 【输出样例】
 86
 */

// #include <bits/stdc++.h>
#include <iostream>

/*
 本题金字塔只有两个方向，即左下和右下这两个方向可以走，但是需要从顶部走到底部
    a[i][j]可以从a[i - 1][j]或者a[i - 1][j - 1]走到
 
 状态：
    dp[i][j]表示从起点(1, 1)走到(i, j)所经过的数字最大和
 状态转移方程
    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j]
 
 */

using namespace std;

const int N = 1e3 + 10;

int a[N][N], dp[N][N];

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            cin >> a[i][j];
    
    // 处理第一列和对角线，对角线只能斜向到达，第一列只能纵向到达
    for(int i = 1; i <= n; i++)
    {
        // 处理第一列
        dp[i][1] = dp[i - 1][1] + a[i][1];
        // 处理对角线
        dp[i][i] = dp[i - 1][i - 1] + a[i][i];
    }
    
    for(int i = 3; i <= n; i++)
        for(int j = 2; j < i; j++)
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
    
    // 输出dp结果
//    for(int i = 1; i <= n; i++)
//    {
//        for(int j = 1; j <= i; j++)
//            cout << dp[i][j] << '\t';
//        cout << endl;
//    }
    
    // 本题要求最大的数字和，而且是走到最后一行的，那就遍历最后一行取最大值
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}
