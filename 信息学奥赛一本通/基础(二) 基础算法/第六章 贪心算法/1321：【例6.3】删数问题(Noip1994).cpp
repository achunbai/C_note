//
//  1321：【例6.3】删数问题(Noip1994).cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/26.
//

/*
 1321：【例6.3】删数问题(Noip1994)

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 43079     通过数: 15558
 【题目描述】
 输入一个高精度的正整数n，去掉其中任意s个数字后剩下的数字按原左右次序组成一个新的正整数。编程对给定的n和s，寻找一种方案使得剩下的数字组成的新数最小。

 输出新的正整数。（n不超过240位）

 输入数据均不需判错。

 【输入】
 n

 s

 【输出】
 最后剩下的最小数。

 【输入样例】
 175438
 4
 【输出样例】
 13
 */

// #include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

// 贪心策略1
//      1. 每次重新从头重新向尾扫描，删除第一个左边数字比右边大的，删除左边的数字
//      2. 如果1不满足，则说明此时数字升序排序，就每次删除最后一个
// 字符串后面补个零可以实现两条合并，只判断第一条即可

int main(int argc, const char * argv[])
{
    int n;
    string num;
    cin >> num;
    cin >> n;
    // 补零
    num += "0";
    for(int i = 0; i < n; i++)
    {
        // 每次从头到尾扫描找到第一个左边大于右边的，删除左边的
        for(int j = 0; j < num.size() - 1; j++)
        {
            if(num[j] > num[j + 1])
            {
                // 删除j位置迭代器
                num.erase(num.begin() + j);
                break;
            }
        }
    }
    num.pop_back();
    // 输出去除前导0
    // 因为要按照数字去处理，目前是按照字符串来处理的，对0的处理不尽人意
    cout << stoi(num) << endl;
    return 0;
}
