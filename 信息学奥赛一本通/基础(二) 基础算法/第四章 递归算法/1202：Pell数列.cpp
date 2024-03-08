//
//  1202：Pell数列.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/24.
//

/*
 1202：Pell数列

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 60626     通过数: 17744
 【题目描述】
 Pell数列a1,a2,a3,...
 的定义是这样的，a1=1,a2=2,...,an=2an−1+an−2(n>2)
 。

 给出一个正整数 k
 ，要求Pell数列的第 k
  项模上 32767
  是多少。

 【输入】
 第1行是测试数据的组数 n
 ，后面跟着 n
  行输入。每组测试数据占 1
  行，包括一个正整数k(1≤k<1000000)
 。

 【输出】
 n
  行，每行输出对应一个输入。输出应是一个非负整数。

 【输入样例】
 2
 1
 8
 【输出样例】
 1
 408
 */

// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int m = 32767;

// 太复杂了，有很多冗余运算，全部超时
int getPell_original(int n)
{
    if(n == 1)
        return 1;
    else if(n == 2)
        return 2;
    else return (getPell_original(n - 1)%m + getPell_original(n - 1)%m + getPell_original(n - 2)%m)%m;
}

// 记忆化搜索/剪枝
const int N = 1e6 + 10;
int pell[N];
int getPell(int n)
{
    if(n <= 0)
        return 0;
    if(pell[n])
        return pell[n];
    if(n <= 2)
        // 先赋值，赋值结束后返回
        return pell[n] = n;
    return pell[n] = (getPell(n - 1)%m + getPell(n - 1)%m + getPell(n - 2)%m)%m;
}

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
//    for(int i = 0; i < n; i++)
//    {
//        int x;
//        cin >> x;
//        cout << getPell(x) << endl;
//    }
    getPell(1e6);
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cout << pell[x] << endl;
    }
    return 0;
}
