/*
1411：区间内的真素数

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 42960     通过数: 17121
【题目描述】
找出正整数M和N之间（N不小于M）的所有真素数。

真素数的定义：如果一个正整数P为素数，且其反序也为素数，那么P就为真素数。

例如，11，13均为真素数，因为11的反序还是为11，13的反序为31也为素数。

【输入】
输入两个数M和N，空格间隔，1<=M<=N<=100000。

【输出】
按从小到大输出M和N之间（包括M和N）的真素数，逗号间隔。如果之间没有真素数，则输出No。

【输入样例】
10 35
【输出样例】
11,13,17,31
*/
/*
#include <stdio.h>
#include <stdlib.h>

// 生成素数列表的函数
int *GetPrime(int MaxNum)
{
    // 初始化素数列表
    int *Prime = (int*)calloc(MaxNum + 1, sizeof(int));
    Prime[0] = Prime[1] = 1;
    // 使用埃拉托斯特尼筛法生成素数列表
    for (int i = 2; i <= MaxNum; i++)
    {
        for (int j = i + i; j <= MaxNum; j += i)
        {
            if(!Prime[j])
            {
                Prime[j] = 1;
            }
        }
    }
    return Prime;
}

// 获取一个数的反序数的函数
int ReverseNum(int num)
{
    int ReversedNum = 0;
    while (num)
    {
        ReversedNum = ReversedNum * 10 + num % 10;
        num /= 10;
    }
    return ReversedNum;
}

// 主函数
int main()
{
    int m, n, flag = 0;
    // 读取输入的m和n
    scanf("%d %d", &m, &n);
    // 生成素数列表
    int *Prime = GetPrime(100000);
    // 对于m到n之间的每一个数
    for (int i = m; i <= n; i++)
    {
        // 如果它和它的反序数都是素数
        if(!Prime[i] && !Prime[ReverseNum(i)])
        {
            // 输出它
            if(flag)
            {
                printf(",");
            }
            printf("%d", i);
            flag = 1;
        }
    }
    // 如果没有找到真素数，输出"No"
    if(!flag)
    {
        printf("No\n");
    }
    else
    {
        printf("\n");
    }
    // 释放素数列表的内存
    free(Prime);
    return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 快速幂取模函数
long long fastPow(long long base, long long power, long long mod)
{
    long long result = 1;
    while (power > 0)
    {
        if (power & 1)
        {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        power >>= 1;
    }
    return result;
}

// Miller-Rabin素数测试
int isPrime(int num, int iteration)
{
    if (num < 2)
    {
        return 0;
    }
    if (num != 2 && num % 2 == 0)
    {
        return 0;
    }
    long long s = num - 1;
    while (s % 2 == 0)
    {
        s /= 2;
    }
    for (int i = 0; i < iteration; i++)
    {
        long long a = rand() % (num - 1) + 1, temp = s;
        long long mod = fastPow(a, temp, num);
        while (temp != num - 1 && mod != 1 && mod != num - 1)
        {
            mod = (mod * mod) % num;
            temp *= 2;
        }
        if (mod != num - 1 && temp % 2 == 0)
        {
            return 0;
        }
    }
    return 1;
}

// 获取一个数的反序数的函数
int ReverseNum(int num)
{
    int ReversedNum = 0;
    while (num)
    {
        ReversedNum = ReversedNum * 10 + num % 10;
        num /= 10;
    }
    return ReversedNum;
}

// 主函数
int main()
{
    srand(time(NULL));
    int m, n, flag = 0;
    scanf("%d %d", &m, &n);
    for (int i = m; i <= n; i++)
    {
        if(isPrime(i, 5) && isPrime(ReverseNum(i), 5))
        {
            if(flag)
            {
                printf(",");
            }
            printf("%d", i);
            flag = 1;
        }
    }
    if(!flag)
    {
        printf("No\n");
    }
    else
    {
        printf("\n");
    }
    return 0;
}
*/

#include <stdio.h>

// 判断一个数是否为素数的函数
int isPrime(int Num)
{
    // 如果Num小于2，那么它不是素数
    if(Num < 2)
    {
        return 0;
    }
    // 检查2到sqrt(Num)之间的所有数是否能整除Num
    for (int i = 2; i * i <= Num; i++)
    {
        if(Num % i == 0)
        {
            return 0;
        }
    }
    // 如果没有找到能整除Num的数，那么Num是素数
    return 1;
}

// 获取一个数的反序数的函数
int ReverseNum(int num)
{
    int ReversedNum = 0;
    while (num)
    {
        ReversedNum = ReversedNum * 10 + num % 10;
        num /= 10;
    }
    return ReversedNum;
}

// 主函数
int main()
{
    int m, n, flag = 0;
    // 读取输入的m和n
    scanf("%d %d", &m, &n);
    // 对于m到n之间的每一个数
    for (int i = m; i <= n; i++)
    {
        // 如果它和它的反序数都是素数
        if(isPrime(i) && isPrime(ReverseNum(i)))
        {
            // 输出它
            if(flag)
            {
                printf(",");
            }
            printf("%d", i);
            flag = 1;
        }
    }
    // 如果没有找到真素数，输出"No"
    if(!flag)
    {
        printf("No\n");
    }
    else
    {
        printf("\n");
    }
    return 0;
}
