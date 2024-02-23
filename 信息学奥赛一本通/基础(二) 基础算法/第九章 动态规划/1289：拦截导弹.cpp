//
//  1289：拦截导弹.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/2/19.
//

/*
 1289：拦截导弹

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 15266     通过数: 9678
 【题目描述】
 某国为了防御敌国的导弹袭击，发展出一种导弹拦截系统。但是这种导弹拦截系统有一个缺陷：虽然它的第一发炮弹能够到达任意的高度，但是以后每一发炮弹都不能高于前一发的高度。某天，雷达捕捉到敌国的导弹来袭。由于该系统还在试用阶段，所以只有一套系统，因此有可能不能拦截所有的导弹。

 输入导弹依次飞来的高度(雷达给出的高度数据是不大于30000的正整数)，计算这套系统最多能拦截多少导弹。

 【输入】
 第一行是一个整数N(不超过15)，表示导弹数。

 第二行包含N个整数，为导弹依次飞来的高度(雷达给出的高度数据是不大于30000的正整数)。

 【输出】
 一个整数，表示最多能拦截的导弹数。

 【输入样例】
 8
 389 207 155 300 299 170 158 65
 【输出样例】
 6
 */

// #include <bits/stdc++.h>
#include <iostream>
#include <climits>

using namespace std;

/*
 状态：
    dp_dec[i] 到第i枚导弹为止能拦截的导弹个数（最大非增子序列）
 
 状态转移方程：
    i为当前，j为遍历之前的所有元素
    if(missle[i] <= missle[j]) dp_dec[i] = max(dp_dec[i], dp_dec[j] + 1)
 */

const int N = 1e3 + 10;
int missle[N], dp_dec[N];

int main(int argc, const char * argv[])
{
    int n, max_dec = INT_MIN;
    cin >> n;
    
    for(int i = 1; i <= n; i++)
    {
        cin >> missle[i];
        dp_dec[i] = 1;
    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j < i; j++)
        {
            // 决策，找到最长非增子序列长度
            if(missle[i] <= missle[j])
                dp_dec[i] = max(dp_dec[i], dp_dec[j] + 1);
        }
        max_dec = max(max_dec, dp_dec[i]);
    }
    
    cout << max_dec << endl;
    return 0;
}
