/*
1405：质数的和与积

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 28781     通过数: 21531
【题目描述】
两个质数的和是S，它们的积最大是多少？

【输入】
一个不大于10000的正整数S，为两个质数的和。

【输出】
一个整数，为两个质数的最大乘积。数据保证有解。

【输入样例】
50
【输出样例】
589
*/
#include <stdio.h>
#include <stdlib.h>

// 使用埃拉托斯特尼筛法找出所有小于等于n的素数
int* GetPrime(int n)
{
    int *Prime = (int*)calloc(n + 1, sizeof(int)); // 分配存储素数的空间，初始化为0（表示是素数）
    for (int i = 2; i <= n; i++) // 从2开始，遍历所有的数
    {
        for (int j = i + i; j <= n; j += i) // 对于每一个数i，将它的所有倍数标记为非素数
        {
            if(!Prime[j]) // 如果这个数还没有被标记为非素数
            {
                Prime[j] = 1; // 标记为非素数
            }
        }
    }
    return Prime; // 返回素数数组
}

int main()
{
    int n, *Prime = GetPrime(10000); // 获取所有小于等于10000的素数
    scanf("%d", &n); // 读取n
    for (int i = n / 2; i > 1; i--) // 从n的一半开始向下遍历
    {
        if(!Prime[i] && !Prime[n - i]) // 如果i和n-i都是素数
        {
            printf("%d\n", i * (n - i)); // 输出它们的乘积
            return 0;
        }
    }
    free(Prime); // 释放存储素数的空间
    return 0;
}