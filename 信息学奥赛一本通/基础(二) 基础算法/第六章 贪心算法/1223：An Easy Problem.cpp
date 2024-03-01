//
//  1223：An Easy Problem.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/29.
//

/*
 1223：An Easy Problem

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 14712     通过数: 10210
 【题目描述】
 给定一个正整数N
 ，求最小的、比N
 大的正整数M
 ，使得M
 与N
 的二进制表示中有相同数目的1
 。

 举个例子，假如给定的N
 为78
 ，其二进制表示为1001110
 ，包含4
 个1
 ，那么最小的比N
 大的并且二进制表示中只包含4
 个1
 的数是83
 ，其二进制是1010011
 ，因此83
 就是答案。

 【输入】
 输入若干行，每行一个数n
 (1≤n≤1000000
 )，输入"0
 "结束。

 【输出】
 输出若干行对应的值。

 【输入样例】
 1
 2
 3
 4
 78
 0
 【输出样例】
 2
 4
 5
 8
 83
 */

// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;

int bin[30];

int DecToBin(int n)
{
    int pos = 0;
    while (n > 0)
    {
        bin[pos] = n % 2;
        n /= 2;
        if(bin[pos] == 1)
        pos++;
    }
    return pos;
}

int Get1Pos(int& len)
{
    for(int i = 0; i < len; i++)
    {
        if(bin[i] == 1 && bin[i + 1] == 0)
        {
            if(i == len - 1)
                len++;
            return i;
        }
    }
    return -1;
}

int BinToDec(int len)
{
    int ret = 0;
    for(int i = len - 1; i >= 0; i--)
    {
        ret = ret * 2 + bin[i];
    }
    return ret--;
}

int main(int argc, const char * argv[])
{
    int n;
    while (cin >> n && n != 0)
    {
        memset(bin, 0, sizeof(bin));
        // 转换为二进制
        int bin_len = DecToBin(n);
        // 获取第一个连续1的位置，如果为头，则长度+1
        int bin_pos = Get1Pos(bin_len);
        // 将为连续1开头的位置置0，前面置1，模拟进位
        bin[bin_pos + 1] = 1;
        bin[bin_pos] = 0;
        // 后面的用sort直接从大到小排（因为倒序存储）
        sort(bin, bin + bin_pos, greater<int>());
        cout << BinToDec(bin_len) << endl;
    }
    return 0;
}
