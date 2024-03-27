//
//  1204：爬楼梯.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/24.
//

/*
 1204：爬楼梯

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 37117     通过数: 20438
 【题目描述】
 树老师爬楼梯，他可以每次走1级或者2级，输入楼梯的级数，求不同的走法数。

 例如：楼梯一共有3级，他可以每次都走一级，或者第一次走一级，第二次走两级，也可以第一次走两级，第二次走一级，一共3种方法。

 【输入】
 输入包含若干行，每行包含一个正整数N，代表楼梯级数，1≤N≤30。

 【输出】
 不同的走法数，每一行输入对应一行输出。

 【输入样例】
 5
 8
 10
 【输出样例】
 8
 34
 89
 */

// #include <bits/stdc++.h>
#include <iostream>
#define int long long

using namespace std;

const int N = 40;

int steps[N];

int getSteps(int n)
{
    if(steps[n])
        return steps[n];
    if(n <= 2)
        return steps[n] = n;
    return (steps[n - 1] = getSteps(n - 1)) + (steps[n - 2] = getSteps(n - 2));
}

signed main(signed argc, const char * argv[])
{
    int n;
    while(cin >> n)
    {
        cout << getSteps(n) << endl;
    }
    return 0;
}
