/*
1167：再求f(x,n)

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 26024     通过数: 20064
【题目描述】
已知



用递归函数求解。

【输入】
第一数是x的值，第二个数是n的值。

【输出】
函数值。

【输入样例】
1 2
【输出样例】
0.40
*/
#include <stdio.h>

// f(x,n)函数的实现
long double SolveFunction(double x, int n)
{
    // 如果n为1，直接返回x / (1 + x)
    if(n == 1)
    {
        return x / (1 + x);
    }
    // 如果n大于1，递归计算f(x,n)的值
    else
    {
        return x / (n + SolveFunction(x, n - 1));
    }
}

int main()
{
    int n;
    double x;
    // 读取输入的x和n
    scanf("%lf %d", &x, &n);
    // 计算f(x,n)的值并打印
    printf("%.2Lf\n", SolveFunction(x, n));
    return 0;
}
