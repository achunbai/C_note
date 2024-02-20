//
//  1196：踩方格.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/24.
//

/*
 1196：踩方格

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 21603     通过数: 14575
 【题目描述】
 有一个方格矩阵，矩阵边界在无穷远处。我们做如下假设：

 a、每走一步时，只能从当前方格移动一格，走到某个相邻的方格上；

 b、走过的格子立即塌陷无法再走第二次；

 c、只能向北、东、西三个方向走；

 请问：如果允许在方格矩阵上走n步，共有多少种不同的方案。2种走法只要有一步不一样，即被认为是不同的方案。

 【输入】
 允许在方格上行走的步数n(n≤20)。

 【输出】
 计算出的方案数量。

 【输入样例】
 2
 【输出样例】
 7
 */

// #include <bits/stdc++.h>
#include <iostream>
#define int long long

using namespace std;

const int N = 21;

int L[N], R[N], U[N];

signed main(signed argc, const char * argv[])
{
    for(int i = 1; i < N; i++)
    {
        if(i == 1)
            L[i] = R[i] = U[i] = 1;
        else
        {
            L[i] = L[i - 1] + U[i - 1];
            R[i] = R[i - 1] + U[i - 1];
            U[i] = L[i - 1] + R[i - 1] + U[i - 1];
        }
    }
    int n;
    cin >> n;
    cout << L[n] + R[n] + U[n] << endl;
    return 0;
}
