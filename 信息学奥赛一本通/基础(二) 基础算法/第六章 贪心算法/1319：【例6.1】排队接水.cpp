//
//  1319：【例6.1】排队接水.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/26.
//

/*
 1319：【例6.1】排队接水

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 40908     通过数: 20003
 【题目描述】
 有n
 个人在一个水龙头前排队接水，假如每个人接水的时间为Ti ，请编程找出这n 个人排队的一种顺序，使得n 个人的平均等待时间最小。

 【输入】
 共两行，第一行为n(1≤n≤1000) ；第二行分别表示第1 个人到第n 个人每人的接水时间T1，T2，…，Tn ，每个数据之间有1 个空格。

 【输出】
 有两行，第一行为一种排队顺序，即1 到n 的一种排列；第二行为这种排列方案下的平均等待时间(输出结果精确到小数点后两位)。

 【输入样例】
 10
 56 12 1 99 1000 234 33 55 99 812

 【输出样例】
 3 2 7 8 1 4 9 6 10 5
 291.90
 */

#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef struct Person
{
    int id;
    int t;
}P;

bool cmp(P a, P b)
{
    return a.t < b.t;
}

const int N = 1e3 + 10;

P p[N];
int sum[N];

signed main(signed argc, const char * argv[])
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> p[i].t;
        p[i].id = i;
    }
    sort(p + 1, p + n + 1, cmp);
    double t = 0;
    for(int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + p[i].t;
        t += sum[i];
        cout << p[i].id << " ";
    }
    t =  (t - sum[n]) / n;
    printf("\n%.2lf\n", t);
    return 0;
}
