//
//  1209：分数求和.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/25.
//

/*
 1209：分数求和

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 18732     通过数: 10421
 【题目描述】
 输入n
 个分数并对他们求和，并用最简形式表示。所谓最简形式是指：分子分母的最大公约数为1
 ；若最终结果的分母为1
 ，则直接用整数表示。

 如：56、103
 均是最简形式，而36
 需要化简为12,31
 需要化简为3
 。

 分子和分母均不为0
 ，也不为负数。

 【输入】
 第一行是一个整数n
 ，表示分数个数，1≤n≤10
 ；

 接下来n
 行，每行一个分数，用"p/q
 "的形式表示，不含空格，p，q
 均不超过10
 。

 【输出】
 输出只有一行，即最终结果的最简形式。若为分数，用"p/q
 "的形式表示。

 【输入样例】
 2
 1/2
 1/3
 【输出样例】
 5/6
 */

// #include <bits/stdc++.h>
#include <iostream>
#define int long long

using namespace std;

const int N = 20;

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

signed main(signed argc, const char * argv[])
{
    int n;
    cin >> n;
    int a, b, c, d, g;
    scanf("%lld/%lld", &a, &b);
    for(int i = 1; i < n; i++)
    {
        scanf("%lld/%lld", &c, &d);
        // 通分
        a = a * d + b * c;
        b = b * d;
        // 约分
        g = gcd(a, b);
        a /= g;
        b /= g;
    }
    if(b == 1)
        cout << a << endl;
    else
        cout << a << "/" << b << endl;
    
    return 0;
}
