//
//  1201：菲波那契数列.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/24.
//

/*
 1201：菲波那契数列

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 40502     通过数: 23783
 【题目描述】
 菲波那契数列是指这样的数列: 数列的第一个和第二个数都为1，接下来每个数都等于前面2个数之和。

 给出一个正整数a，要求菲波那契数列中第a个数是多少。

 【输入】
 第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，包括一个正整数a(1<=a<=20)。

 【输出】
 输出有n行，每行输出对应一个输入。输出应是一个正整数，为菲波那契数列中第a个数的大小。

 【输入样例】
 4
 5
 2
 19
 1
 【输出样例】
 5
 1
 4181
 1
 */

// #include <bits/stdc++.h>
#include <iostream>
#define int long long
// 递归或者递推中，如果没有要求模运算，必须开long long

using namespace std;

// 归递边界
// f[1] == f[2] == 1
// 归递关系式
// f(n) = f(n-1) + f(n-2)

int fibonacci(int n)
{
    if(n == 1 | n == 2)
        return 1;
    else if(n <= 0)
        return 0;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

signed main(signed argc, const char * argv[])
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cout << fibonacci(x) << endl;
    }
    return 0;
}
