/*
1155：回文三位数

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 50915     通过数: 33377
【题目描述】
如果一个数从左边读和从右边读都是同一个数，就称为回文数。例如6886就是一个回文数，求出所有的既是回文数又是素数的三位数。

【输入】
(无）

【输出】
所有的既是回文数又是素数的三位数。一个数一行。

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
    // 获取2到1000之间的所有素数
    int* prime = GetPrime(1000);
    // 遍历所有的三位回文数
    for(int i = 1; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            // 计算三位回文数
            int num = i*100+j*10+i;
            // 如果num是素数，那么num就是一个既是回文数又是素数的三位数
            if(!prime[num])
                // 打印出这个数
                printf("%d\n", num);
        }
    }
    // 释放prime数组
    free(prime);
    return 0;
}
