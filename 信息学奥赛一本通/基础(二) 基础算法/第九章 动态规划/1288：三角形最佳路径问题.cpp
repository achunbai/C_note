//
//  1288：三角形最佳路径问题.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/2/17.
//

/*
 1288：三角形最佳路径问题

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 10443     通过数: 8776
 【题目描述】
 如下所示的由正整数数字构成的三角形:

 7
 3 8
 8 1 0
 2 7 4 4
 4 5 2 6 5
 从三角形的顶部到底部有很多条不同的路径。对于每条路径，把路径上面的数加起来可以得到一个和，和最大的路径称为最佳路径。你的任务就是求出最佳路径上的数字之和。

 注意：路径上的每一步只能从一个数走到下一层上和它最近的下边(正下方)的数或者右边（右下方）的数。

 【输入】
 第一行为三角形高度100≥h≥1，同时也是最底层边的数字的数目。

 从第二行开始，每行为三角形相应行的数字，中间用空格分隔。

 【输出】
 最佳路径的长度数值。

 【输入样例】
 5
 7
 3 8
 8 1 0
 2 7 4 4
 4 5 2 6 5
 【输出样例】
 30
 */

// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int N = 1e3 + 10;
int cost[N][N];
int dp[N][N];
/*
 状态：
    dp[i][j]为从顶点(1,1)到(i,j)点的途径数字最大累计和
 状态转移方程：
    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + cost[i][j]
 */

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            cin >> cost[i][j];
    
    // 处理第一列
    for(int i = 1; i <= n; i++)
        dp[i][1] = dp[i - 1][1] + cost[i][1];
    // 处理副对角线
    for(int i = 2; i <= n; i++)
        dp[i][i] = dp[i - 1][i - 1] + cost[i][i];
    
    for(int i = 3; i <= n; i++)
        for(int j = 2; j < i; j++)
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + cost[i][j];
    
    // 输出dp结果
//    for(int i = 1; i <= n; i++)
//    {
//        for(int j = 1; j <= i; j++)
//            cout << dp[i][j] << '\t';
//        cout << endl;
//    }
    
    // 本题要求最大的路径，而且是走到最后一行的，那就遍历最后一行取最大值
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}
