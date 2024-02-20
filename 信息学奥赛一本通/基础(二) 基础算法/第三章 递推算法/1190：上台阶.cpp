//
//  1190：上台阶.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/22.
//

/*
 1190：上台阶

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 71166     通过数: 24386
 【题目描述】
 楼梯有n
 (0<n<71
 )阶台阶,上楼时可以一步上1
 阶,也可以一步上2
 阶,也可以一步上3
 阶，编程计算共有多少种不同的走法。

 【输入】
 输入的每一行包括一组测试数据，即为台阶数n
 。最后一行为0
 ，表示测试结束。

 【输出】
 每一行输出对应一行输入的结果，即为走法的数目。

 【输入样例】
 1
 2
 3
 4
 0
 【输出样例】
 1
 2
 4
 7
 */

// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int N = 72;

int ways[N] = {0, 1, 2, 4};

void getMethod(int ways[])
{
    for(int i = 4; i < N; i++)
    {
        ways[i] = ways[i - 1] + ways[i - 2] + ways[i - 3];
    }
}

int main(int argc, const char * argv[])
{
    getMethod(ways);
    int x;
    while(cin >> x && x != 0)
    {
        cout << ways[x] << endl;
    }
    return 0;
}
