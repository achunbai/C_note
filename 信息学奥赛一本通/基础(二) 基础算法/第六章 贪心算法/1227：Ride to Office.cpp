//
//  1227：Ride to Office.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/28.
//

/*
 1227：Ride to Office

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 11918     通过数: 6871
 【题目描述】
 起点与终点相隔4500
 米。现Charley需要从起点骑车到终点。但是，他有个习惯，沿途需要有人陪伴，即以相同的速度，与另外一个人一起骑。而当他遇到以更快的速度骑车的人时，他会以相应的速度跟上这个更快的人。先给定所有与Charley同路的人各自的速度与出发时间，问Charley以这种方式跟人，骑完4500
 米需要多少时间。得出的结果若是小数，则向上取整。

 【输入】
 输入若干组数据，每组数据第一行n(1≤n≤10000)
 ,n
 为0
 ，表示输入结束，接着输入n
 行数据，每行2个数据，表示速度v
 和出发时间t
 ，如果t<0
 ，表示陪伴人提早出发了。

 【输出】
 输出对应若干行数据，每行输出1个数，表示最快到达的时间。

 【输入样例】
 4
 20 0
 25 -155
 27 190
 30 240
 2
 21 0
 22 34
 0
 【输出样例】
 780
 771
 */

// #include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <climits>

// 贪心策略
//      1. 如果Charlie追上了某人，那么Charlie一定速度快，维持原来的速度
//      2. 如果Charlie在到达终点之前没追上，则提前出发的这个人和Charlie无关
//  综上：
//      对于提前出发的人的到达时间和Charlie无关
//      则Charlie的到达时间仅和晚出发和零时刻出发的到达时间中的最小值

using namespace std;

int main(int argc, const char * argv[])
{
    int n;
    double speed, start_t, arrival_t = INT_MAX;
    while((cin >> n) && n)
    {
        // 多组数据每次一定要重置
        arrival_t = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            cin >> speed >> start_t;
            if(start_t >= 0)
            {
                start_t += 4500 * 3.6 / speed;
                if(start_t < arrival_t)
                    arrival_t = start_t;
            }
        }
        printf("%.0lf\n", ceil(arrival_t));
    }
    return 0;
}
