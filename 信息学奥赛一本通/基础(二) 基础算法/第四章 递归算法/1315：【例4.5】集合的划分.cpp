//
//  1315：【例4.5】集合的划分.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/25.
//

// #include <bits/stdc++.h>
#include <iostream>
#define int long long

using namespace std;
// 状态f(n, k)代表把n个元素按照一定要求划分到k个盒子里面的方案数
int f(int n, int k)
{
    // 边界
    // 如果元素数少于盒子数或者没有盒子，则分不了
    if(n < k || k == 0)
        return 0;
    if(k == 1 || k == n)
        return 1;
    // 归递关系式
    // 情况1：
    //      a[i]是k个子集中的单独一个，则其余n-1个元素划分到剩余的k-1个盒子中f(n - 1, k - 1)
    // 情况2：
    //      a[i]不是k个子集中单独一个，其余n-1个元素划分到k个盒子中f(n - 1, k)
    //      a[i]不是k个子集中单独一个，但是他可以和剩下n-1个元素构成一个集合，即a[i]可以和k个集合中的元素构成新的集合，故总方案数k*f(n - 1, k)
    //
    return f(n - 1, k - 1) + k * f(n - 1, k);
}

const int N = 1e3 + 10;

signed main(signed argc, const char * argv[])
{
    int n, k;
    cin >> n >> k;
    cout << f(n, k) << endl;
    return 0;
}
