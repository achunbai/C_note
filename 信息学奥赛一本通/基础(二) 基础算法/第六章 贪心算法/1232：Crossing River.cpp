//
//  1232：Crossing River.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/30.
//

/*
 1232：Crossing River

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 15655     通过数: 7091
 【题目描述】
 几个人过河，每次过两人一人回，速度由慢者决定，问过河所需最短时间。

 【输入】
 输入t组数据，每组数据第1行输入n，第2行输入n个数，表示每个人过河的时间。

 【输出】
 输出t行数据，每行1个数，表示每组过河最少时间。

 【输入样例】
 1
 4
 1 2 5 10
 【输出样例】
 17
 */

// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;

// 引入——四人过河模型
// a < b < c < d
// a 1, b 2, c 3, d 8
// 策略1：
//      让回来的时间最少，每次让时间最少的带人
//      2*a+b+c+d=16
// 策略2：
//      让过河的时间最少，每次让过河时间相近的两个一起走
//      a+3*b+d=15
//      最后ab一起过，将cd送过去
// 最终最短过河时间：
//      min(m1, m2)

/*
    n人过河问题，需要转换为4人过河问题
        除了最后一次，前面都要保证a，b不过河，和接下来的数据构成4人模型
    策略1：
        2*a + c + d
    策略2：
        a + 2*b + d
    
 */

const int N = 1e5 + 10;

int a[N];

int main(int argc, const char * argv[])
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        for(int j = 0; j < n; j++)
        {
            cin >> a[j];
        }
        sort(a, a + n);
        int ans = 0;
        while (n >= 4)
        {
            ans += min(a[0] * 2 + a[n - 2] + a[n - 1], a[0] + a[1] * 2 + a[n - 1]);
            n -= 2;
        }
        if(n == 2)
            ans += a[1];
        else
            ans += a[0] + a[1] + a[2];
        cout << ans << endl;
    }
    return 0;
}
