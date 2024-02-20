//
//  1314：【例3.6】过河卒(Noip2002).cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/23.
//

/*
 1314：【例3.6】过河卒(Noip2002)

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 40333     通过数: 17605
 【题目描述】
 棋盘上A点有一个过河卒，需要走到目标B点。卒行走的规则：可以向下、或者向右。同时在棋盘上的某一点有一个对方的马（如C点），该马所在的点和所有跳跃一步可达的点称为对方马的控制点，如图3-1中的C点和P1，……，P8，卒不能通过对方马的控制点。棋盘用坐标表示，A点(0,0)、B点(n, m) (n,m为不超过20的整数),同样马的位置坐标是需要给出的，C≠A且C≠B。现在要求你计算出卒从A点能够到达B点的路径的条数。



 【输入】
 给出n、m和C点的坐标。

 【输出】
 从A点能够到达B点的路径的条数。

 【输入样例】
 8 6 0 4
 【输出样例】
 1617
 */

// 第一行或者第一列全为1种方案，其余地方等于上面的方案数+左侧位置的方案数
// 边界
// i == 1 || j == 1; f[i][j] == 1;
// f[i][j] = f[i - 1][j] + f[i][j - 1];
// #include <bits/stdc++.h>
#include <iostream>
#define int long long

using namespace std;

const int N = 1e2 + 10;

// 递推数组
// 从起点(0, 0)到终点(i, j)的方案数量
int method[N][N];
// 二维标记数组，标记马的控制点
bool control[N][N];
// 方向数组
// 标记相对的变化
//               p2  p7  p3  p6 p1 p8 p4  p5
int direct_x[] = {1, 1, -1, -1, 2, 2, -2, -2};
int direct_y[] = {2, -2, 2, -2, -1, 1, 1, -1};

signed main(signed argc, const char * argv[])
{
    int n, m, cx, cy;
    cin >> n >> m >> cx >> cy;
    // 标记马的点
    control[cx][cy] = true;
    for(int i = 0; i < 8; i++)
    {
        int bx = cx + direct_x[i];
        int by = cy + direct_y[i];
        // 如果新生成坐标越界，那么跳过本次循环
        if(bx < 0 || bx > n || by < 0 || by > m)
            continue;
        control[bx][by] = 1;
    }
    // 边界
    method[0][0] = 1;
    // 处理第一列
    for(int i = 1; i <= n; i++)
    {
        method[i][0] = method[i - 1][0];
        // 若为控制点则置0
        if(control[i][0])
            method[i][0] = 0;
    }
    
    // 处理第一行
    for(int i = 1; i <= m; i++)
    {
        method[0][i] = method[0][i - 1];
        // 若为控制点则置0
        if(control[0][i])
            method[0][i] = 0;
    }

    
    // 递推
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            method[i][j] = method[i - 1][j] + method[i][j - 1];
            if(control[i][j])
                method[i][j] = 0;
        }
    }
    // 输出到终点(n, m)的总方案数
    cout << method[n][m] << endl;
    return 0;
}
