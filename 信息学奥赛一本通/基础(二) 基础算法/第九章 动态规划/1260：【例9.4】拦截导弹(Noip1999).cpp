//
//  1260：【例9.4】拦截导弹(Noip1999).cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/2/19.
//

/*
 1260：【例9.4】拦截导弹(Noip1999)

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 33454     通过数: 13637
 【题目描述】
 某国为了防御敌国的导弹袭击，发展出一种导弹拦截系统。但是这种导弹拦截系统有一个缺陷：虽然它的第一发炮弹能够到达任意的高度，但是以后每一发炮弹都不能高于前一发的高度。某天，雷达捕捉到敌国的导弹来袭。由于该系统还在试用阶段，所以只有一套系统，因此有可能不能拦截所有的导弹。

 输入导弹依次飞来的高度（雷达给出的高度数据是不大于30000的正整数，导弹数不超过1000），计算这套系统最多能拦截多少导弹，如果要拦截所有导弹最少要配备多少套这种导弹拦截系统。

 【输入】
 输入导弹依次飞来的高度。

 【输出】
 第一行：最多能拦截的导弹数；

 第二行：要拦截所有导弹最少要配备的系统数。

 【输入样例】
 389 207 155 300 299 170 158 65
 【输出样例】
 6
 2
 */

// #include <bits/stdc++.h>
#include <iostream>
#include <climits>

using namespace std;

/*
 本题需要开两个dp，分别是最长不上升子序列和上升子序列
 最多能拦截的导弹数为最长不上升子序列
 需要的系统套数为最长上升子序列的长度
 Dilworth定理：
    定理1： 其最长链中元素的数目必等于其最小反链划分（即将集合划分为最少的反链）中反链的数目。
    定理2： 其最长反链中元素的数目必等于其最小链划分中链的数目。
    即为：
        原序列可以划分成的*不上升*子序列的最小数量为最长*上升*子序列的长度。
            加重的字只要满足相反的描述即成立
 
 状态：
    dp_dec[i] 到第i枚导弹为止能拦截的导弹个数（最大非增子序列）
    dp_inc[i] 需要的导弹系统数，划分成的最小非增子序列数量，即为到第i枚导弹为止导弹高度的最大上升子序列长度
 
 状态转移方程：
    i为当前，j为遍历之前的所有元素
    if(missle[i] <= missle[j]) dp_dec[i] = max(dp_dec[i], dp_dec[j] + 1)
    if(missle[i] > missle[j]) dp_inc[i] = max(dp_inc[i], dp_inc[j] + 1)
 */

const int N = 1e3 + 10;

int missle[N], dp_dec[N], dp_inc[N];

int main(int argc, const char * argv[])
{
    int len = 0;
    // 输入导弹高度数据，并将dp的值初始化为1
    while(cin >> missle[++len])
        dp_dec[len] = dp_inc[len] = 1;
    len--;
    int max_dec = INT_MIN, max_inc = INT_MIN;
    for(int i = 1; i <= len; i++)
    {
        for(int j = 1; j < i; j++)
        {
            // 决策，找到最长非增子序列和最长上升子序列长度
            if(missle[i] <= missle[j])
                dp_dec[i] = max(dp_dec[i], dp_dec[j] + 1);
            else
                dp_inc[i] = max(dp_inc[i], dp_inc[j] + 1);
        }
        max_dec = max(max_dec, dp_dec[i]);
        max_inc = max(max_inc, dp_inc[i]);
    }
    
    // 输出dp
//    for(int i = 1; i <= len; i++)
//        cout << missle[i] << " ";
//    cout << endl;
//    for(int i = 1; i <= len; i++)
//        cout << dp_inc[i] << " ";
//    cout << endl;
//    for(int i = 1; i <= len; i++)
//        cout << dp_dec[i] << " ";
//    cout << endl;
    
    cout << max_dec << endl << max_inc << endl;
    return 0;
}
