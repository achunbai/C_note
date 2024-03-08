//
//  1231：最小新整数.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/27.
//

/*
 1231：最小新整数

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 12801     通过数: 6909
 【题目描述】
 给定一个十进制正整数n(0<n<1000000000)，每个数位上数字均不为0。n的位数为m。

 现在从m位中删除k位(0<k<m)，求生成的新整数最小为多少？

 例如: n=9128456,k=2,则生成的新整数最小为12456。

 【输入】
 第一行t, 表示有t组数据；

 接下来t行，每一行表示一组测试数据，每组测试数据包含两个数字n,k。

 【输出】
 t行，每行一个数字，表示从n中删除k位后得到的最小整数。

 【输入样例】
 2
 9128456 2
 1444 3
 【输出样例】
 12456
 1
 */

/*
 和1321思路一样
    1. 找到比后面位大的前值，删除前值，补零破坏升序条件
        例： 12345 -> 123450
    2. 删除后加的0，然后调用stolld或者使用erase方法删除前导0，配合find_first_not_of方法
 */

// #include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[])
{
    int n, k;
    string num;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> num >> k;
        num += "0";
        for(int j = 0; j < k; j++)
        {
            for(int l = 0; l < num.size() - 1; l++)
            {
                if(num[l] > num[l + 1])
                {
                    num.erase(num.begin() + l);
                    break;
                }
            }
        }
        num.pop_back();
        // 使用字符串的方式处理前导0
        // num.erase(<#const_iterator __first#>, <#const_iterator __last#>)
        // 直接删除字符串可能安全一些
        // num.find_first_not_of(<#const string &__str#>)
        // 后面和num长度-1取最小值，防止全为0导致找非0值返回的数非常大，引发错误
        num.erase(0, min(num.find_first_not_of('0'), num.size()-1));
        cout << num << endl;
        // 注意本题数据超过了int范围，需要long long
        // 故本题应该调用stoll，而不是stod或者stold
        // cout << stoll(num) << endl;
    }
    return 0;
}
