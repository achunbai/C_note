//
//  1206：放苹果.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/23.
//

/*
 1206：放苹果

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 28442     通过数: 17463
 【题目描述】
 把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？（用K表示）5，1，1和1，5，1 是同一种分法。

 【输入】
 第一行是测试数据的数目t（0<=t<=20）。以下每行均包含二个整数M和N，以空格分开。1<=M，N<=10。

 【输出】
 对输入的每组数据M和N，用一行输出相应的K。

 【输入样例】
 1
 7 3
 【输出样例】
 8
 */

/*
 method[i][j]，i个苹果放进j个盘子方案数
 
 边界：
 i <= 1 || j <= 1
 method[i][j] = 1;
 
 递推关系
 求method[i][j]
 “允许有的盘子空着不放”
    1. 每个盘子至少1个（所有的盘子都不空）
            先把所有盘子都放一个苹果，剩下的方案数看剩下i - j个苹果放进j个盘子的方案数 method[i - j][j]
    2. 至少空一个盘子
        method[i][j - 1]
 */

// #include <bits/stdc++.h>
#include <iostream>
#define int long long

using namespace std;

const int N = 1 + 10;

int result[N][N];

signed main(signed argc, const char * argv[])
{
    int t, m, n;
    cin >> t;
    for(int i = 0; i <= 10; i++)
    {
        for(int j = 0; j <= 10; j++)
        {
            if(i <= 1|| j <=1)
                result[i][j] = 1;
            else if(i < j)
                result[i][j] = result[i][j - 1];
            else
                result[i][j] = result[i - j][j] + result[i][j - 1];
        }
    }
    for(int i = 0; i < t; i++)
    {
        cin >> m >> n;
        cout << result[m][n] << endl;
    }
    return 0;
}
