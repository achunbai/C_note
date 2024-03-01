//
//  1187：统计字符数.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/20.
//

/*
 1187：统计字符数

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 29048     通过数: 16602
 【题目描述】
 给定一个由a-z这26个字符组成的字符串，统计其中哪个字符出现的次数最多。

 【输入】
 输入包含一行，一个字符串，长度不超过1000。

 【输出】
 输出一行，包括出现次数最多的字符和该字符出现的次数，中间以一个空格分开。如果有多个字符出现的次数相同且最多，那么输出ascii码最小的那一个字符。

 【输入样例】
 abbccc
 【输出样例】
 c 3
 */

// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

const int N = 1e3 + 10;

bool cmp(const pair<char, int>& a, const pair<char, int>& b)
{
    return a.second < b.second;
}

int main(int argc, const char * argv[])
{
    string str;
    cin >> str;
    map<char, int> mp;
    for(auto c:str)
    {
        mp[c]++;
    }
    auto mp_max = max_element(mp.begin(), mp.end(), cmp);
    cout << mp_max->first << " " << mp_max->second << endl;
    return 0;
}
