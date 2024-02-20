//
//  1191：流感传染.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/24.
//

/*
 1191：流感传染

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 30562     通过数: 16811
 【题目描述】
 有一批易感人群住在网格状的宿舍区内，宿舍区为n*n的矩阵，每个格点为一个房间，房间里可能住人，也可能空着。在第一天，有些房间里的人得了流感，以后每天，得流感的人会使其邻居传染上流感，（已经得病的不变），空房间不会传染。请输出第m天得流感的人数。

 【输入】
 第一行一个数字n，n不超过100，表示有n*n的宿舍房间。

 接下来的n行，每行n个字符，’.’表示第一天该房间住着健康的人，’#’表示该房间空着，’@’表示第一天该房间住着得流感的人。

 接下来的一行是一个整数m，m不超过100。

 【输出】
 输出第m天，得流感的人数。

 【输入样例】
 5
 ....#
 .#.@.
 .#@..
 #....
 .....
 4
 【输出样例】
 16
 */

// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int N = 1e2 + 10;

char room[N][N];
bool infection[N][N];

int main(int argc, const char * argv[])
{
    int n, m, cnt = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> room[i][j];
        }
    }
    cin >> m;
    for(int k = 0; k < m; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(room[i][j] == '@')
                {
                    if(room[i-1][j] == '.')
                        infection[i-1][j] = '@';
                    if(room[i+1][j] == '.')
                        infection[i+1][j] = '@';
                    if(room[i][j-1] == '.')
                        infection[i][j-1] = '@';
                    if(room[i][j+1] == '.')
                        infection[i][j+1] = '@';
                }
                if(infection[i][j])
                {
                    room[i][j] = '@';
                }
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(room[i][j] == '@' || infection[i][j])
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
