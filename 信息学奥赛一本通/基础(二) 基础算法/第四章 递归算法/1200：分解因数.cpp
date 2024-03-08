//
//  1200：分解因数.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/25.
//

/*
 1200：分解因数

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 25229     通过数: 14199
 【题目描述】
 给出一个正整数a
 ，要求分解成若干个正整数的乘积，即a=a1×a2×a3×...×an
 ，并且1<a1≤a2≤a3≤...≤an
 ，问这样的分解的种数有多少。注意到a=a
 也是一种分解。

 【输入】
 第1行是测试数据的组数n
 ，后面跟着n
 行输入。每组测试数据占1
 行，包括一个正整数a(1<a<32768)
 。

 【输出】
 n
 行，每行输出对应一个输入。输出应是一个正整数，指明满足要求的分解的种数。

 【输入样例】
 2
 2
 20
 【输出样例】
 1
 4
 */

// #include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#define int long long

using namespace std;


// 从k开始分解n
int getMethod(int n, int k)
{
    // 边界，分解结束
    if(n == 1)
        return 1;
    int cnt = 0;
    for(int i = k; i <= n; i++)
    {
        // 代表此时n可以分解
        if(n % i == 0)
            // 之前的分解完了，既然i为因子，那后续都从i开始分解
            cnt += getMethod(n / i, i);
    }
    return cnt;
}

// 从k开始分解n
int method = 1;
void getMethod2(int n, int k)
{
    // 边界，分解结束
    if(n == 1)
        return;
    for(int i = k; i <= sqrt(n); i++)
    {
        // 代表此时n可以分解
        if(n % i == 0)
        {
            // 之前的分解完了，既然i为因子，那后续都从i开始分解
            // 同时要保证后续的分解大于等于之前的分解
            method++;
            getMethod2(n / i, i);
        }
    }
}

signed main(signed argc, const char * argv[])
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        method = 1;
        getMethod2(x, 2);
        cout << method << endl;
    }
    return 0;
}
