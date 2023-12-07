/*
2019：【例4.4】求阶乘

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 121198     通过数: 47782
【题目描述】
利用for循环求n!
的值。

提示，n!=1×2×...×n
。

【输入】
输入一个正整数n
。

【输出】
输出n!
的值。

【输入样例】
4
【输出样例】
24
【提示】
【数据规模及约定】

对于所有数据，1≤n≤20。

注意result的范围，使用unsigned long或者long long类型。
对应的格式控制符为%lu或者%lld。
*/

/*
#include <stdio.h>

int main() 
{
    int n;
    unsigned long result = 1;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }
    printf("%lu", result);
    return 0;
}
*/

#include <stdio.h>

int main() 
{
    int n;
    long long result = 1;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }
    printf("%lld", result);
    return 0;
}