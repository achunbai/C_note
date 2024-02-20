//
//  1312：【例3.4】昆虫繁殖.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/22.
//

/*
 1312：【例3.4】昆虫繁殖

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 46450     通过数: 23086
 【题目描述】
 科学家在热带森林中发现了一种特殊的昆虫，这种昆虫的繁殖能力很强。每对成虫过x
 个月产y
 对卵，每对卵要过两个月长成成虫。假设每个成虫不死，第一个月只有一对成虫，且卵长成成虫后的第一个月不产卵(过x
 个月产卵)，问过z
 个月以后，共有成虫多少对？0≤x≤20,1≤y≤20,X≤z≤50
 。

 【输入】
 x,y,z
 的数值。

 【输出】
 过z
 个月以后，共有成虫对数。

 【输入样例】
 1 2 8
 【输出样例】
 37
 */

// #include <bits/stdc++.h>
#include <iostream>
// 递推的题目，如果没有声明模运算，统一开long long
#define int long long

using namespace std;

const int N = 1e2 + 10;

int eggs[N], bugs[N];

void getBugs_Eggs(int x, int y, int z)
{
    for(int i = 1; i <= x; i++)
    {
        bugs[i] = 1;
        eggs[i] = 0;
    }
    for(int i = x + 1; i <= z + 1; i++)
    {
        eggs[i] = bugs[i - x] * y;
        bugs[i] = eggs[i - 2] + bugs[i - 1];
    }
}

signed main(signed argc, const char * argv[])
{
    int x, y, z;
    cin >> x >> y >> z;
    getBugs_Eggs(x, y, z);
    cout << bugs[z + 1] << endl;
    return 0;
}
