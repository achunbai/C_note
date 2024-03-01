//
//  1225：金银岛.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/26.
//

/*
 1225：金银岛

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 19408     通过数: 10863
 【题目描述】
 某天KID利用飞行器飞到了一个金银岛上，上面有许多珍贵的金属，KID虽然更喜欢各种宝石的艺术品，可是也不拒绝这样珍贵的金属。但是他只带着一个口袋，口袋至多只能装重量为w的物品。岛上金属有s
 个种类, 每种金属重量不同，分别为n1,n2,...,ns
 ，同时每个种类的金属总的价值也不同，分别为v1,v2,...,vs
 。KID想一次带走价值尽可能多的金属，问他最多能带走价值多少的金属。注意到金属是可以被任意分割的，并且金属的价值和其重量成正比。

 【输入】
 第1行是测试数据的组数k
 ，后面跟着k
 组输入。

 每组测试数据占3行，第1行是一个正整数w(1≤w≤10000)
 ，表示口袋承重上限。第2行是一个正整数s(1≤s≤100)
 ，表示金属种类。第3行有2s
 个正整数，分别为n1,v1,n2,v2,...,ns,vs
 分别为第一种，第二种，...，第s
 种金属的总重量和总价值(1≤ni≤10000,1≤vi≤10000)
 。

 【输出】
 k
 行，每行输出对应一个输入。输出应精确到小数点后2
 位。

 【输入样例】
 2
 50
 4
 10 100 50 30 7 34 87 100
 10000
 5
 1 43 43 323 35 45 43 54 87 43
 【输出样例】
 171.93
 508.00
 */

#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef struct metal
{
    int weight;
    int val;
    long double val_pw;
}M;

bool cmp(M a, M b)
{
    return a.val_pw > b.val_pw;
}
const int N = 1e4 + 10;

M m[N];

signed main(signed argc, const char * argv[])
{
    int n, bag, metal_k;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> bag >> metal_k;
        long double val_sum = 0;
        for(int j = 0; j < metal_k; j++)
        {
            cin >> m[j].weight >> m[j].val;
            m[j].val_pw = (long double)m[j].val / m[j].weight;
        }
        sort(m, m + metal_k, cmp);
        for(int j = 0; j < metal_k; j++)
        {
            // 对于第i件物品，一定是当前所有物品中单位价格最高的
            // 能装得下就全装
            if(bag >= m[j].weight)
            {
                bag -= m[j].weight;
                val_sum += m[j].val;
            }
            // 装不下，能装多少装多少
            else if(bag > 0)
            {
                // 剩余背包容量*物品单位价值
                val_sum += bag * m[j].val_pw;
                break;
            }
            else
                break;
        }
        printf("%.2Lf\n", val_sum);
    }
    return 0;
}
