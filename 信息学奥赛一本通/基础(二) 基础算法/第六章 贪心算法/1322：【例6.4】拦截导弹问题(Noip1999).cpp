//
//  1322：【例6.4】拦截导弹问题(Noip1999).cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/28.
//

/*
 1322：【例6.4】拦截导弹问题(Noip1999)

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 38214     通过数: 15051
 【题目描述】
 某国为了防御敌国的导弹袭击，开发出一种导弹拦截系统，但是这种拦截系统有一个缺陷：虽然它的第一发炮弹能够到达任意的高度，但是以后每一发炮弹都不能高于前一发的高度。某天，雷达捕捉到敌国的导弹来袭，由于该系统还在试用阶段。所以一套系统有可能不能拦截所有的导弹。

 输入导弹依次飞来的高度（雷达给出的高度不大于30000的正整数）。计算要拦截所有导弹最小需要配备多少套这种导弹拦截系统。

 【输入】
 n颗依次飞来的高度（1≤n≤1000）。

 【输出】
 要拦截所有导弹最小配备的系统数k。

 【输入样例】
 389 207 155 300 299 170 158 65
 【输出样例】
 2
 【提示】
 输入：导弹高度： 4  3  2

 输出：导弹拦截系统k=1
 */

// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int N = 1e3 + 10;

int missle[N];
// 标记第i个导弹是否已经被拦截
bool blocked[N];

int main(int argc, const char * argv[])
{
    int n = 0, cnt = 0, block_cnt = 0, h;
    // 这种输入方式通常以EOF结尾
    while(cin >> missle[n++]);
    // 因为读入优EOF结尾，且EOF算输入，故n会多1
    n--;
    while(block_cnt < n)
    {
        // 每次训话重置为最高的导弹高度
        h = 3e4;
        for(int i = 0; i < n; i++)
        {
            // 注意等号，小于等于之前高度的导弹都可以被拦截
            if(!blocked[i] && missle[i] <= h)
            {
                blocked[i] = true;
                block_cnt++;
                h = missle[i];
            }
        }
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
