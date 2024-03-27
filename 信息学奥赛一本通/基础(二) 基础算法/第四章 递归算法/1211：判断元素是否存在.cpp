//
//  1211：判断元素是否存在.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/25.
//

/*
 1211：判断元素是否存在

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 27026     通过数: 11150
 【题目描述】
 有一个集合M是这样生成的：(1) 已知k是集合M的元素； (2) 如果y是M的元素，那么，2y+1和3y+1都是M的元素；(3) 除了上述二种情况外，没有别的数能够成为M的一个元素。

 问题：任意给定k和x，请判断x是否是M的元素。这里的k是无符号整数，x 不大于 100000，如果是，则输出YES，否则，输出NO。

 【输入】
 输入整数 k 和 x, 逗号间隔。

 【输出】
 如果是，则输出 YES，否则，输出NO。

 【输入样例】
 0,22
 【输出样例】
 YES
 */

// #include <bits/stdc++.h>
#include <iostream>
#define int long long

using namespace std;

bool findx(int k, int x)
{
    if(k == x)
        return true;
    if(k > x)
        return false;
    return findx(2 * k + 1, x) || findx(3 * k + 1, x);
}

signed main(signed argc, const char * argv[])
{
    int k, x;
    scanf("%lld,%lld", &k, &x);
    if(findx(k, x))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
