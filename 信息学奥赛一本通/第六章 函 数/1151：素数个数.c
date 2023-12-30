/*
1151：素数个数

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 80940     通过数: 47636
【题目描述】
编程求2∼n
(n
为大于2
的正整数)中有多少个素数。

【输入】
输入n(2≤n≤50000)
。

【输出】
素数个数。

【输入样例】
10
【输出样例】
4
*/
#include <stdio.h>
#include <stdlib.h>

// 定义一个函数，用于获取2到n之间的所有素数
int* GetPrime(int n)
{
    // 使用calloc函数分配一个大小为(n + 1)的整数数组，所有元素初始化为0
    int* prime = (int*)calloc(n + 1, sizeof(int));
    // 从2开始遍历到n
    for (int i = 2; i <= n; i++)
    {
        // 如果prime[i]为0，表示i是一个素数
        if(!prime[i])
        {
            // 将i的所有倍数标记为非素数
            for (int j = i + i; j <= n ; j += i)
            {
                prime[j] = 1;
            }
        }
    }
    // 返回prime数组
    return prime;
}

int main()
{
    int n, cnt = 0;
    // 读取输入的n
    scanf("%d", &n);
    // 获取2到n之间的所有素数
    int* prime = GetPrime(n);
    // 遍历prime数组，计算素数的个数
    for (int i = 2; i <= n; i++)
    {
        // 如果prime[i]为0，表示i是一个素数，cnt加1
        if(!prime[i])
            cnt++;
    }
    // 打印素数的个数
    printf("%d", cnt);
    // 释放prime数组
    free(prime);
    return 0;
}


