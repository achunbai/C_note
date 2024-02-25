//
//  1184：明明的随机数.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/20.
//

/*
 1184：明明的随机数

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 43214     通过数: 27196
 【题目描述】
 明明想在学校中请一些同学一起做一项问卷调查，为了实验的客观性，他先用计算机生成了N个1到1000之间的随机整数（N≤100），对于其中重复的数字，只保留一个，把其余相同的数去掉，不同的数对应着不同的学生的学号。然后再把这些数从小到大排序，按照排好的顺序去找同学做调查。请你协助明明完成“去重”与“排序”的工作。

 【输入】
 有2行，第1行为1个正整数，表示所生成的随机数的个数：N；

 第2行有N个用空格隔开的正整数，为所产生的随机数。

 【输出】
 也是2行，第1行为1个正整数M，表示不相同的随机数的个数。第2行为M个用空格隔开的正整数，为从小到大排好序的不相同的随机数。

 【输入样例】
 10
 20 40 32 67 40 20 89 300 400 15
 【输出样例】
 8
 15 20 32 40 67 89 300 400
 */

// #include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    set<int> nums;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.insert(x);
    }
    cout << nums.size() << endl;
    for(auto n:nums)
    {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
