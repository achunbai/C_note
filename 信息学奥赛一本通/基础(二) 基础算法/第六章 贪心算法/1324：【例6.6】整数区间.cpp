//
//  1324：【例6.6】整数区间.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/26.
//

/*
 1324：【例6.6】整数区间

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 17681     通过数: 10563
 【题目描述】
 请编程完成以下任务：

 1.读取闭区间的个数及它们的描述；

 2.找到一个含元素个数最少的集合,使得对于每一个区间,都至少有一个整数属于该集合，输出该集合的元素个数。

 【输入】
 首行包括区间的数目n
 ,1≤n≤10000
 ,接下来的n
 行,每行包括两个整数a,b
 ,被一空格隔开,0≤a≤b≤10000
 ,它们是某一个区间的开始值和结束值。

 【输出】
 第一行集合元素的个数,对于每一个区间都至少有一个整数属于该集合,且集合所包含元素数目最少。

 【输入样例】
 4
 3 6
 2 4
 0 2
 4 7
 【输出样例】
 2
 */

// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#define int long long

using namespace std;

/*
 0 2 -> 2
 2 9 -> 2
 3 6 -> 6
 4 7 -> 6

 0 3
 1 2
 2 4
 2 3
 3 7
 4 5

 1. 按照L升序排列
 2. 首个默认尾元素加入集合
 3. 比较元素和下一个的首元素比较，若小于则直接开新的，若大于则和后者尾元素取小值，更新现值
 */

const int N = 1e3 + 10;

typedef struct Segment
{
    int L;
    int R;
}S;

S s[N];

bool cmp(S a, S b)
{
    return a.R < b.R;
}

signed main(signed argc, const char * argv[])
{
    int n, tmp, cnt = 1;
    cin >> n >> s[0].L >> s[0].R;
    tmp = s[0].R;
    for(int i = 1; i < n; i++)
    {
        cin >> s[i].L >> s[i].R;
    }
    sort(s, s + n, cmp);
    for(int i = 1; i < n; i++)
    {
        if(s[i].L < tmp)
        {
            tmp = tmp < s[i].R ? tmp : s[i].R;
        }
        else if(s[i].L == tmp)
        {
            cnt++;
        }
        else
        {
            cnt++;
            tmp = s[i].R;
        }
    }
    cout << cnt << endl;
    return 0;
}
