//
//  1188：菲波那契数列(2).cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/22.
//

/*
 1188：菲波那契数列(2)

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 68981     通过数: 26285
 【题目描述】
 菲波那契数列是指这样的数列: 数列的第一个和第二个数都为1
 ，接下来每个数都等于前面2
 个数之和。

 给出一个正整数a
 ，要求菲波那契数列中第a
 个数对1000
 取模的结果是多少。

 【输入】
 第1
 行是测试数据的组数n
 ，后面跟着n
 行输入。每组测试数据占1行，包括一个正整数a(1≤a≤1000000)
 。

 【输出】
 n
 行，每行输出对应一个输入。输出应是一个正整数，为菲波那契数列中第a
 个数对1000
 取模得到的结果。

 【输入样例】
 4
 5
 2
 19
 1
 【输出样例】
 5
 1
 181
 1
 */

// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int N = 1e6+10;

int fibonacci[N] = {0, 1, 1};

void getFibonacci(int fibonacci[])
{
    for(int i = 3; i <= N; i++)
    {
        fibonacci[i] = (fibonacci[i - 1]%1000 + fibonacci[i - 2]%1000 ) %1000;
    }
}

int main(int argc, const char * argv[])
{
    int a, x;
    getFibonacci(fibonacci);
    cin >> a;
    for(int i = 0; i < a; i++)
    {
        cin >> x;
        cout << fibonacci[x] << endl;
    }
    return 0;
}
