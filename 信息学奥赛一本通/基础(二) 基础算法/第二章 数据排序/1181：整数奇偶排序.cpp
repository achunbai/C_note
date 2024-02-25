//
//  1181：整数奇偶排序.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/20.
//

/*
 1181：整数奇偶排序

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 35497     通过数: 23030
 【题目描述】
 给定10个整数的序列，要求对其重新排序。排序要求:

 1.奇数在前，偶数在后；

 2.奇数按从大到小排序；

 3.偶数按从小到大排序。

 【输入】
 输入一行，包含10个整数，彼此以一个空格分开，每个整数的范围是大于等于0，小于等于30000。

 【输出】
 按照要求排序后输出一行，包含排序后的10个整数，数与数之间以一个空格分开。

 【输入样例】
 4 7 3 13 11 12 0 47 34 98
 【输出样例】
 47 13 11 7 3 0 4 12 34 98
 */

#include <bits/stdc++.h>

using namespace std;

typedef struct INT
{
    int num;
    bool isOdd;
}INT;

INT num[10];

bool cmp(INT a, INT b)
{
    if(a.isOdd != b.isOdd)
        return a.isOdd > b.isOdd;
    else if(a.isOdd && b.isOdd)
        return a.num > b.num;
    else return a.num < b.num;
}

int main(int argc, const char * argv[])
{
    for(int i = 0; i < 10; i++)
    {
        cin >> num[i].num;
        num[i].isOdd = num[i].num % 2;
    }
    sort(num, num + 10, cmp);
    for(int i = 0; i < 10; i++)
    {
        cout << num[i].num << " ";
    }
    cout << endl;
    return 0;
}
