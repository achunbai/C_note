/*
1410：最大质因子序列

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 23866     通过数: 16312
【题目描述】
任意输入两个正整数m,n(1<m<n≤5000)
，依次输出m
到n
之间每个数的最大质因子(包括m
和n
；如果某个数本身是质数，则输出这个数自身)。

【输入】
一行，包含两个正整数m
和n
，其间以单个空格间隔。

【输出】
一行，每个整数的最大质因子，以逗号间隔。

【输入样例】
5 10
【输出样例】
5,3,7,2,3,5
*/
#include <stdio.h>
#include <stdlib.h>

// 获取质数的函数，返回一个数组，数组的索引是数字，值为1表示不是质数，值为0表示是质数
int *GetPrime(int MaxNum)
{
    int *Prime = (int*)calloc(MaxNum + 1, sizeof(int));
    Prime[0] = Prime[1] = 1;  // 0和1不是质数
    for (int i = 2; i * i <= MaxNum; i++)  // 只需要遍历到根号MaxNum
    {
        if (!Prime[i])  // 如果i是质数，那么i的倍数不是质数
        {
            for (int j = i * i; j <= MaxNum; j += i)
            {
                Prime[j] = 1;  // 标记非质数
            }
        }
    }
    return Prime;
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int *Prime = GetPrime(n);  // 获取质数标记数组
    for (int i = m; i <= n; i++)  // 遍历m到n之间的所有数字
    {
        for (int j = i; j > 1; j--)  // 从i开始向下遍历，找出最大的质因子
        {
            if(i % j == 0 && !Prime[j])  // 如果j是i的因子并且j是质数，那么j就是i的最大质因子
            {
                printf("%d", j);
                break;
            }
        }
        if(i != n)  // 如果不是最后一个数字，输出逗号
        {
            printf(",");
        }
    }
    free(Prime);  // 释放内存
    return 0;
}