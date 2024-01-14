/*
1165：Hermite多项式

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 45868     通过数: 21013
【题目描述】
用递归的方法求Hermite多项式的值

hn(x)=⎧⎩⎨⎪⎪12x2xhn−1(x)−2(n−1)hn−2(x)n=0n=1n>1
 
对给定的x
和正整数n
，求多项式的值。

【输入】
给定的n
和正整数x
。

【输出】
多项式的值。

【输入样例】
1 2
【输出样例】
4.00
*/
#include <stdio.h>

// Hermite多项式的实现
double SolveHermitePolynomial(int n, int x)
{
    // 如果n为0，直接返回1
    if(n == 0)
    {
        return 1;
    }
    // 如果n为1，直接返回2x
    else if(n == 1)
    {
        return 2 * x;
    }
    // 如果n大于1，递归计算Hermite多项式的值
    else if(n > 1)
    {
        return 2 * x * SolveHermitePolynomial(n - 1, x) - 2 * (n - 1) * SolveHermitePolynomial(n - 2, x);
    }
    // 其他情况返回-1，实际上这种情况不会发生，因为题目已经限定了n的取值范围
    else
    {
        return -1;
    }
}

int main()
{
    int n, x;
    // 读取输入的n和x
    scanf("%d %d", &n, &x);
    // 计算Hermite多项式的值并打印
    printf("%.2lf\n", SolveHermitePolynomial(n, x));
    return 0;
}
