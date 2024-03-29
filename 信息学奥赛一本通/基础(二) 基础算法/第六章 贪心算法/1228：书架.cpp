//
//  1228：书架.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/26.
//

/*
 1228：书架

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 17900     通过数: 10373
 【题目描述】
 John最近买了一个书架用来存放奶牛养殖书籍，但书架很快被存满了，只剩最顶层有空余。

 John共有N
 头奶牛(1≤N≤20,000
 )，每头奶牛有自己的高度Hi(1≤Hi≤10,000)
 ，N头奶牛的总高度为S
 。书架高度为B(1≤B≤S<2,000,000,007)
 。

 为了到达书架顶层，奶牛可以踩着其他奶牛的背，像叠罗汉一样，直到他们的总高度不低于书架高度。当然若奶牛越多则危险性越大。为了帮助John到达书架顶层，找出使用奶牛数目最少的解决方案吧。

 【输入】
 第1行：空格隔开的整数N
 和B
 。

 第2~N+1行：第i+1
 行为整数Hi
 。

 【输出】
 能达到书架高度所使用奶牛的最少数目。

 【输入样例】
 6 40
 6
 18
 11
 13
 19
 11
 【输出样例】
 3
 */

// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#define int long long

using namespace std;

const int N = 2e4 + 10;

int cow[N];

signed main(signed argc, const char * argv[])
{
    int n, b, cnt = 0, h = 0;
    cin >> n >> b;
    for(int i = 0; i < n; i++)
    {
        cin >> cow[i];
    }
    sort(cow, cow + n, greater<int>());
    for(int i = 0; i < n; i++)
    {
        if(h >= b)
            break;
        h += cow[i];
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
