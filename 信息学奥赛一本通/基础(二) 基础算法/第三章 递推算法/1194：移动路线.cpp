//
//  1194：移动路线.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/24.
//

/*
 1194：移动路线

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 22185     通过数: 16837
 【题目描述】
 X桌子上有一个m行n列的方格矩阵，将每个方格用坐标表示，行坐标从下到上依次递增，列坐标从左至右依次递增，左下角方格的坐标为(1,1)，则右上角方格的坐标为(m,n)。

 小明是个调皮的孩子，一天他捉来一只蚂蚁，不小心把蚂蚁的右脚弄伤了，于是蚂蚁只能向上或向右移动。小明把这只蚂蚁放在左下角的方格中，蚂蚁从

 左下角的方格中移动到右上角的方格中，每步移动一个方格。蚂蚁始终在方格矩阵内移动，请计算出不同的移动路线的数目。

 对于1行1列的方格矩阵，蚂蚁原地移动，移动路线数为1；对于1行2列（或2行1列）的方格矩阵，蚂蚁只需一次向右（或向上）移动，移动路线数也为1……对于一个2行3列的方格矩阵，如下图所示：

 (2,1)    (2,2)    (2,3)
 (1,1)    (1,2)    (1,3)
 蚂蚁共有3种移动路线：

 路线1：(1,1) → (1,2) → (1,3) → (2,3)

 路线2：(1,1) → (1,2) → (2,2) → (2,3)

 路线3：(1,1) → (2,1) → (2,2) → (2,3)

 【输入】
 输入只有一行，包括两个整数m和n（0 < m+n ≤ 20），代表方格矩阵的行数和列数，m、n之间用空格隔开。

 【输出】
 输出只有一行，为不同的移动路线的数目。

 【输入样例】
 2 3
 【输出样例】
 3
 */

// 边界
// x == 1 || y == 1      method[x][y] = 1
// 递推关系
// method[x][y] = method[x - 1][y] + method[x][y - 1]

// #include <bits/stdc++.h>
#include <iostream>
#define int long long

using namespace std;

const int N = 21;

int method[N][N];

signed main(signed argc, const char * argv[])
{
    int m, n;
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == 1 || j == 1)
                method[i][j] = 1;
            else
                method[i][j] = method[i - 1][j] + method[i][j - 1];
        }
    }
    cout << method[m][n] << endl;
    return 0;
}
