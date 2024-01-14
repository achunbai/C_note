/*
1153：绝对素数

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 64927     通过数: 38590
【题目描述】
如果一个自然数是素数,且它的数字位置经过对换后仍为素数,则称为绝对素数,例如13。试求出所有二位绝对素数。

【输入】
（无）

【输出】
所有二位绝对素数（由小到大，一个数一行）。

【输入样例】
（无）
【输出样例】
（无）
*/
#include <stdio.h>
#include <stdlib.h>

// 定义一个函数，用于获取2到n之间的所有素数
int* GetPrime(int n)
{
    // 使用calloc函数分配一个大小为n的整数数组，所有元素初始化为0
    int* prime = (int*)calloc(n, sizeof(int));
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
    // 获取2到100之间的所有素数
    int* prime = GetPrime(100);
    // 遍历所有两位数
    for (int i = 10; i < 100; i++)
    {
        // 如果i和i的数字反转后的数都是素数，那么i就是一个绝对素数
        if(!prime[i] && !prime[i%10*10+i/10])
        {
            // 打印出绝对素数
            printf("%d\n", i);
        }
    }
    // 释放prime数组
    free(prime);
    return 0;
}
