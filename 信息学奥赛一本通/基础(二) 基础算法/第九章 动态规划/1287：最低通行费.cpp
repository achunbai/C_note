//
//  1287：最低通行费.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/2/17.
//

/*
 1287：最低通行费

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 12572     通过数: 8704
 【题目描述】
 一个商人穿过一个N×N的正方形的网格，去参加一个非常重要的商务活动。他要从网格的左上角进，右下角出。每穿越中间1个小方格，都要花费1个单位时间。商人必须在(2N-1)个单位时间穿越出去。而在经过中间的每个小方格时，都需要缴纳一定的费用。

 这个商人期望在规定时间内用最少费用穿越出去。请问至少需要多少费用？

 注意：不能对角穿越各个小方格（即，只能向上下左右四个方向移动且不能离开网格）。

 【输入】
 第一行是一个整数，表示正方形的宽度N (1≤N<100)；

 后面N行，每行N个不大于100的整数，为网格上每个小方格的费用。

 【输出】
 至少需要的费用。

 【输入样例】
 5
 1  4  6  8  10
 2  5  7  15 17
 6  8  9  18 20
 10 11 12 19 21
 20 23 25 29 33
 【输出样例】
 109
 【提示】
 样例中，最小值为109=1+2+5+7+9+12+19+21+33。
 */

// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

// 本题n <= 100
const int N = 1e2 + 10;
int cost[N][N];
int dp[N][N];
/*
 状态：
    dp[i][j]表示从原点到(i,j)所需要花费的最少费用
 状态转移方程：
    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + cost[i][j]
 */

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> cost[i][j];
    // 处理第一行和第一列
    for(int i = 1; i <= n; i++)
    {
        // 处理第一列
        dp[i][1] = dp[i - 1][1] + cost [i][1];
        // 处理第一行
        dp[1][i] = dp[1][i - 1] + cost [1][i];
    }
    
    for(int i = 2; i <= n; i++)
        for(int j = 2; j <= n && i + j <= n * 2; j++)
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + cost[i][j];
    
//    for(int i = 1; i <= n; i++)
//    {
//        for(int j = 1; j <= n; j++)
//            cout << dp[i][j] << "\t";
//        cout << endl;
//    }
    
    cout << dp[n][n] << endl;
    return 0;
}
