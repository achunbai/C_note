//
//  1207：求最大公约数问题.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/24.
//

/*
 1207：求最大公约数问题

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 35674     通过数: 21634
 【题目描述】
 给定两个正整数，求它们的最大公约数。

 【输入】
 输入一行，包含两个正整数(<1,000,000,000)。

 【输出】
 输出一个正整数，即这两个正整数的最大公约数。

 【输入样例】
 6 9
 【输出样例】
 3
 */

// #include <bits/stdc++.h>
#include <iostream>

// lcm = a*b / gcd

using namespace std;

// gcd(a, b) = gcd(b, a%b)
int gcd(int a, int b)
{
//    if(b == 0)
//        return a;
//    return gcd(b, a % b);
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b)
{
    // 最好先不算a*b，防止乘法出现数值过大，爆int、long long
    return a / gcd(a, b) * b;
}

int main(int argc, const char * argv[])
{
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    return 0;
}
