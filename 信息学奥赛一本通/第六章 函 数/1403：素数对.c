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

int* GetPrime(int n)
{
    int *Prime = (int*)calloc(n + 1, sizeof(int));
    for (int i = 2; i <= n; i++)
    {
        for (int j = i + i; j <= n; j += i)
        {
            if(!Prime[j])
            {
                Prime[j] = 1;
            }
        }
    }
    return Prime;
}

int main()
{
    int n, *Prime = GetPrime(10000);
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        if(!Prime[i] && !Prime[i + 2])
        {
            printf("%d %d\n", i, i + 2);
        }
    }
    free(Prime);
    return 0;
}