//
//  1283：登山.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/2/19.
//

/*
 1283：登山

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 26374     通过数: 9617
 【题目描述】
 五一到了，ACM队组织大家去登山观光，队员们发现山上一共有N个景点，并且决定按照顺序来浏览这些景点，即每次所浏览景点的编号都要大于前一个浏览景点的编号。同时队员们还有另一个登山习惯，就是不连续浏览海拔相同的两个景点，并且一旦开始下山，就不再向上走了。队员们希望在满足上面条件的同时，尽可能多的浏览景点，你能帮他们找出最多可能浏览的景点数么？

 【输入】
 第一行：N (2 <= N <= 1000) 景点数;

 第二行：N个整数，每个景点的海拔。

 【输出】
 最多能浏览的景点数。

 【输入样例】
 8
 186 186 150 200 160 130 197 220
 【输出样例】
 4
 */

// #include <bits/stdc++.h>
#include <iostream>
#include <climits>

using namespace std;

const int N = 1e3 + 10;
/*
 本题需要求最大上升子序列和逆向的最大上升子序列
 下山后不上山，海拔相同不重复看
 
 状态：
    dp_inc[i] 从起点开始到第i个点为终点最大的上升子序列长度
    dp_dec[i] 从第i个点开始，到终点的最大下降子序列长度（从终点到第i个点逆向的最大上升子序列长度）
 
 状态转移方程：
    if(height[i] > height[j]) dp_inc[i] = max(dp_inc[i], dp_inc[j] + 1)
    if(height[i] > height[j]) dp_dec[i] = max(dp_dec[i], dp_dec[j] + 1)
 
 */

int height[N], dp_inc[N], dp_dec[N];

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    // 输入+初始化序列，都为1
    for(int i = 1; i <= n; i++)
    {
        cin >> height[i];
        dp_inc[i] = dp_dec[i] = 1;
    }

    // 求正向的最大上升子序列长度
    for(int i = 1; i <= n; i++)
        for(int j = 1; j < i; j++)
            if(height[i] > height[j])
                dp_inc[i] = max(dp_inc[i], dp_inc[j] + 1);
    
    // 求逆向的最大上升子序列长度
    for(int i = n; i >= 1; i--)
        for(int j = i; j <= n; j++)
            if(height[i] > height[j])
                dp_dec[i] = max(dp_dec[i], dp_dec[j] + 1);
    
    // 遍历正向和逆向的结果，得到最终的答案
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, dp_inc[i] + dp_dec[i] - 1);
    
    cout << ans << endl;
    return 0;
}
