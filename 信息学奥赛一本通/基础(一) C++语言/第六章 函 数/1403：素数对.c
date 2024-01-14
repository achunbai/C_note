/*
1403：素数对

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 35050     通过数: 25742
【题目描述】
两个相差为2的素数称为素数对，如5和7，17和19等，本题目要求找出所有两个数均不大于n的素数对。

【输入】
一个正整数n(1≤n≤10000)。

【输出】
所有小于等于n的素数对。每对素数对输出一行，中间用单个空格隔开。若没有找到任何素数对，输出empty。

【输入样例】
100
【输出样例】
3 5
5 7
11 13
17 19
29 31
41 43
59 61
71 73
*/
#include <stdio.h>
#include <stdlib.h>

// 获取小于等于n的所有素数
int* GetPrime(int n)
{
    // 初始化一个大小为n+1的数组，用于标记每个数是否为素数，0表示是素数，1表示不是素数
    int *Prime = (int*)calloc(n + 1, sizeof(int));
    // 从2开始遍历到n
    for (int i = 2; i <= n; i++)
    {
        // 将i的倍数全部标记为非素数
        for (int j = i + i; j <= n; j += i)
        {
            if(!Prime[j])
            {
                Prime[j] = 1;
            }
        }
    }
    // 返回标记数组
    return Prime;
}

int main()
{
    int n;
    // 获取小于等于10000的所有素数
    int *Prime = GetPrime(10000);
    // 读取输入的n
    scanf("%d", &n);
    // 遍历2到n，找出所有的素数对
    for (int i = 2; i <= n; i++)
    {
        // 如果i和i+2都是素数，那么它们就是一个素数对
        if(!Prime[i] && !Prime[i + 2])
        {
            printf("%d %d\n", i, i + 2);
        }
    }
    // 释放内存
    free(Prime);
    return 0;
}
