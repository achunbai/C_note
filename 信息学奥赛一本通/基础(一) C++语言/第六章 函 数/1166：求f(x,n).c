/*
1166：求f(x,n)

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 33549     通过数: 22190
【题目描述】
已知

f(x,n)=n+(n−1)+(n−2)+...+2+1+x‾‾‾‾‾√‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾√‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾√‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾√‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾√
计算x=4.2，n=10
以及x=2.5，n=15
时的f
的值。

【输入】
输入x
和n
。

【输出】
函数值，保留两位小数。

【输入样例】
4.2 10
【输出样例】
3.68
*/
#include <stdio.h>
#include <math.h>

// f(x,n)函数的实现
double SolveFunction(double x, int n)
{
    // 如果n为1，直接返回sqrt(x + 1)
    if(n == 1)
    {
        return sqrt(x + 1);
    }
    // 如果n大于1，递归计算f(x,n)的值
    else
    {
        return sqrt(n + SolveFunction(x, n - 1));
    }
}

int main()
{
    int n;
    double x;
    // 读取输入的x和n
    scanf("%lf %d", &x, &n);
    // 计算f(x,n)的值并打印
    printf("%.2lf\n", SolveFunction(x, n));
    return 0;
}
