//
//  1316：【例4.6】数的计数(Noip2001).cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/25.
//

/*
 1316：【例4.6】数的计数(Noip2001)

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 40432     通过数: 17412
 【题目描述】
 我们要求找出具有下列性质数的个数（包括输入的自然数n
 ）。先输入一个自然数n(n≤1000)
 ，然后对此自然数按照如下方法进行处理：

 不作任何处理；

 在它的左边加上一个自然数，但该自然数不能超过原数的一半；

 加上数后，继续按此规则进行处理，直到不能再加自然数为止。

 【输入】
 自然数n(n≤1000)
 。

 【输出】
 满足条件的数。

 【输入样例】
 6
 【输出样例】
 6
 【提示】
 【样例解释】

 满足条件的数为如下所示：

    6
   16
   26
  126
   36
  136
 */

#include <bits/stdc++.h>
#include <iostream>
#define int long long

using namespace std;

const int N = 1e3 + 10;

int method[N] = {0, 1, 2};

void test(int n)
{
    // 从3开始计算
    for(int i = 3; i <= n; i++)
    {
        // 每次从前往后，method[i] = method[1] + method[2] + ..... + method[i / 2]
        for(int j = 1; j <= i / 2; j++)
        {
            method[i] += method[j];
        }
        method[i]++;
    }
    cout << method[n] << endl;
}

int getVal(int n)
{
    if(n <= 2)
        return n;
    if(method[n])
        return method[n];
    int tmp = 0;
    for(int i = 0; i <= n / 2; i++)
        tmp += getVal(i);
    tmp++;
    return method[n] = tmp;
}

signed main(signed argc, const char * argv[])
{
    int n;
    cin >> n;
    // test(n);
    cout << getVal(n) << endl;
    return 0;
}
