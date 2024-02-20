//
//  1259：【例9.3】求最长不下降序列.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/2/19.
//

// #include <bits/stdc++.h>
#include <iostream>

/*
 本题需要求最长的不下降序列，上升和等于都算
 状态
     dp[i] 表示以第一个元素作为结尾的最长上升子序列长度
 状态转移方程
     if(a[j] <= a[i]) dp[i] = max(dp[i], dp[j] + 1)
 
 打印路径可以使用pre数组
 */

using namespace std;

const int N = 1e3 + 10;

int dp[N], a[N], pre[N];

void ReversePrint(int idx)
{
    if(idx == 0)
        return;
    ReversePrint(pre[idx]);
    cout << a[idx] << " ";
}

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    
    // 输入并将dp[i]初始化为1，即默认所有值的最长不下降序列为自身
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = 1;
    }
    
    int ans = 0, idx = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j < i; j++)
        {
            if(a[j] <= a[i])
            {
                if(dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                }
            }
        }
        if(ans < dp[i])
        {
            ans = dp[i];
            idx = i;
        }
        ans = max(ans, dp[i]);
    }
    
    cout << "max=" << ans << endl;
    // 逆向打印序列，使用递归可以正向打印
//    while(pre[idx] > 0)
//    {
//        cout << a[idx] << " ";
//        idx = pre[idx];
//    }
//    cout << a[idx] << endl;
    // 调用递归的正向打印
    ReversePrint(idx);
    cout << endl;
    return 0;
}
