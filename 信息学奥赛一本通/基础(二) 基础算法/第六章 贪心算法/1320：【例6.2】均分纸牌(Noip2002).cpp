//
//  1320：【例6.2】均分纸牌(Noip2002).cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/28.
//

/*
 1320：【例6.2】均分纸牌(Noip2002)

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 30490     通过数: 16895
 【题目描述】
 有n堆纸牌，编号分别为 1，2，…,n
 。每堆上有若干张，但纸牌总数必为n
 的倍数。可以在任一堆上取若干张纸牌，然后移动。

 移牌规则为：在编号为1
 的堆上取的纸牌，只能移到编号为 2
  的堆上；在编号为 n
  的堆上取的纸牌，只能移到编号为n−1
 的堆上；其他堆上取的纸牌，可以移到相邻左边或右边的堆上。

 现在要求找出一种移动方法，用最少的移动次数使每堆上纸牌数都一样多。

 例如 n=4
 ，4
 堆纸牌数分别为：  ①　9　②　8　③　17　④　6

 移动3次可达到目的：

 从 ③ 取4张牌放到④（9 8 13 10）->从③取3张牌放到 ②（9 11 10 10）-> 从②取1张牌放到①（10 10 10 10）。

 【输入】
 n
 （n
  堆纸牌，1≤n≤100
 ）

 a1a2…an
  （n
  堆纸牌，每堆纸牌初始数，l≤ai≤10000
 ）。

 【输出】
 所有堆均达到相等时的最少移动次数。

 【输入样例】
 4
 9 8 17 6
 【输出样例】
 3
 */

// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

// 核心思路
// 双向变单向，从左往右遍历，直接移动变平均值就行

const int N = 1e2 + 10;

int cards[N];

int main(int argc, const char * argv[])
{
    int n, cnt = 0, sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> cards[i];
        sum += cards[i];
    }
    sum /= n;
    for(int i = 0; i < n - 1; i++)
    {
        if(cards[i] != sum)
        {
            cards[i + 1] -= sum - cards[i];
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
