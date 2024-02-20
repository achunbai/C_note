//
//  1264：【例9.8】合唱队形.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/2/19.
//

/*
 1264：【例9.8】合唱队形

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 24289     通过数: 12050
 【题目描述】
 N
 位同学站成一排，音乐老师要请其中的(N−K)
 位同学出列，使得剩下的K
 位同学排成合唱队形。

 合唱队形是指这样的一种队形：设K
 位同学从左到右依次编号为1,2,…,K
 ，他们的身高分别为T1,T2,…,TK
 ，则他们的身高满足T1<T2<…<Ti,Ti>Ti+1>…>TK(1≤i≤K)
 。

 你的任务是，已知所有N
 位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。

 【输入】
 输入的第一行是一个整数N（2≤N≤100）
 ，表示同学的总数。第二行有n
 个整数，用空格分隔，第i
 个整数Ti（130≤Ti≤230）
 是第i
 位同学的身高（厘米）。

 【输出】
 输出包括一行，这一行只包含一个整数，就是最少需要几位同学出列。

 【输入样例】
 8
 186 186 150 200 160 130 197 220
 【输出样例】
 4
 【提示】
 对于50%的数据，保证有n≤20
 ；

 对于全部的数据，保证有n≤100
 。
 */

// #include <bits/stdc++.h>
#include <iostream>

/*
 a  1   2   3   4   5   6   7   8
    186 186 150 200 160 130 197 220
 
 以第i个元素结尾的最长上升
 dp_inc 1   2   3   4   5   6   7   8
        1   1   1   2   2   1   3   4
 
 以第i个元素开头的最长下降
    倒着看就是以第i个元素结尾的最长上升
 dp_dec 1   2   3   4   5   6   7   8
        3   3   2   3   2   1   1   1
 */

using namespace std;

const int N = 1e2 + 10;

int a[N], dp_inc[N], dp_dec[N];

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp_inc[i] = dp_dec[i] = 1;
    }
    
    // 正着遍历，取以第i个元素结尾的最长上升序列
    for(int i = 1; i <= n; i++)
        for(int j = 1; j < i; j++)
            if(a[i] > a[j])
                dp_inc[i] = max(dp_inc[i], dp_inc[j] + 1);
    
    // 倒着遍历，取以第i个元素结尾的最长上升序列
    for(int i = n; i >= 1; i--)
        for(int j = i + 1; j <= n; j++)
            if(a[i] > a[j])
                dp_dec[i] = max(dp_dec[i], dp_dec[j] + 1);
    
    // 定义输出的结果，注意同一个人不能出现在两个队列中，所以人数要-1
    int max_val = 0;
    for(int i = 1; i <= n; i++)
        max_val = max(max_val, dp_inc[i] + dp_dec[i] - 1);
    
    // 注意是出列的人数，目前求的是留在队列中的人数
    cout << n - max_val << endl;
    return 0;
}
