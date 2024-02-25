//
//  1186：出现次数超过一半的数.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/19.
//

/*
 1186：出现次数超过一半的数

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 39429     通过数: 18257
 【题目描述】
 给出一个含有n（0 < n <= 1000）个整数的数组，请找出其中出现次数超过一半的数。数组中的数大于-50且小于50。

 【输入】
 第一行包含一个整数n，表示数组大小；

 第二行包含n个整数，分别是数组中的每个元素，相邻两个元素之间用单个空格隔开。

 【输出】
 如果存在这样的数，输出这个数；否则输出no。

 【输入样例】
 3
 1 2 2
 【输出样例】
 2
 */
// #include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

int main(int argc, const char * argv[])
{
    map<int, int> mp;
    int n, target;
    cin >> n;
    target = n / 2;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
        if(mp[x] > target)
        {
            cout << x << endl;
            return 0;
        }
    }
    cout << "no" << endl;
    return 0;
}
