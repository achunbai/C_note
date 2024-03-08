//
//  1323：【例6.5】活动选择.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/26.
//

/*
 1323：【例6.5】活动选择

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 27338     通过数: 15219
 【题目描述】
 学校在最近几天有n
 个活动，这些活动都需要使用学校的大礼堂，在同一时间，礼堂只能被一个活动使用。由于有些活动时间上有冲突，学校办公室人员只好让一些活动放弃使用礼堂而使用其他教室。

 现在给出n
 个活动使用礼堂的起始时间begini
 和结束时间endi(begini<endi)
 ，请你帮助办公室人员安排一些活动来使用礼堂，要求安排的活动尽量多。

 【输入】
 第一行一个整数n(n≤1000)
 ；

 接下来的n
 行，每行两个整数，第一个begini
 ，第二个是endi(begini<endi≤32767)
 。

 【输出】
 输出最多能安排的活动个数。

 【输入样例】
 11
 3 5
 1 4
 12 14
 8 12
 0 6
 8 11
 6 10
 5 7
 3 8
 5 9
 2 13
 【输出样例】
 4
 */

#include <bits/stdc++.h>

using namespace std;

// segment 片段，区间

typedef struct Event
{
    int l;
    int r;
}E;

const int N = 1e3 + 10;

E e[N];

// 贪心原则，优先选择结束时间早的
int cmp (E a, E b)
{
    return a.r < b.r;
}

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> e[i].l >> e[i].r;
    }
    sort(e, e + n, cmp);
    // 第一个区间必选，尾区间为0
    int cnt = 1, idx = 0;
    for(int i = 1; i < n; i++)
    {
        // 新进来的区间开始时间比结束时间晚就拼上去
        // 其实时间相等也行，前一个一结束后一个就跟上来
        if(e[i].l >= e[idx].r)
        {
            idx = i;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
