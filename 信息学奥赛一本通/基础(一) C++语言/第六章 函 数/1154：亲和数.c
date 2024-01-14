/*
1154：亲和数

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 53696     通过数: 32422
【题目描述】
自然数a的因子是指能整除a的所有自然数，但不含a本身。例如12的因子为：1,2,3,4,6。若自然数a的因子之和为b，而且b的因子之和又等于a，则称a,b为一对“亲和数” 。求最小的一对亲和数(a<>b)。

【输入】
(无）

【输出】
1行，分别为a和b(a<b)。

【输入样例】
（无）
【输出样例】
（无）
*/
#include <stdio.h>

// 定义一个函数，用于计算一个数的真因数之和
int GetSumOfDivisors(int n)
{
    int sum = 1;
    // 从2开始遍历到n的平方根
    for (int i = 2; i * i <= n; i++)
    {
        // 如果n能被i整除，那么i就是n的一个因数
        if(n % i == 0)
        {
            // 将i加到sum中
            sum += i;
            // 如果i不等于n的平方根，那么n/i也是n的一个因数
            // 将n/i加到sum中
            if(i * i != n) 
                sum += n / i;
        }
    }
    // 返回真因数之和
    return sum;
}

int main()
{
    // 从1开始遍历所有的数
    for (int i = 1; ; i++)
    {
        // 计算i的真因数之和
        int b = GetSumOfDivisors(i);
        // 如果i小于b，并且b的真因数之和等于i，那么i和b就是一对亲和数
        if(i < b && GetSumOfDivisors(b) == i)
        {
            // 打印出亲和数
            printf("%d %d\n", i, b);
            // 找到一对亲和数后，程序就结束
            return 0;
        }
    }
    return 0;
}
