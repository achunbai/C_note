/*
1152：最大数max(x,y,z)

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 55526     通过数: 38561
【题目描述】
已知:

m=max(a,b,c)max(a+b,b,c)×max(a,b,b+c)
输入a,b,c
，求m
。把求三个数的最大数max(x,y,z)
分别定义成函数和过程来做。

【输入】
输入a,b,c
。

【输出】
求m
，保留到小数点后三位。

【输入样例】
1 2 3
【输出样例】
 0.200
*/
#include <stdio.h>

// 定义一个函数，用于获取三个数中的最大值
int GetMax(int a, int b, int c)
{
    if(a > b && a > c)
        return a;
    else if(b > a && b > c)
        return b;
    else
        return c;
}

int main()
{
    int a, b, c;
    // 读取输入的三个整数a, b, c
    scanf("%d %d %d", &a, &b, &c);
    // 计算最大的那个数除以(a+b, b, c)和(a, b, b+c)中最大的那个数的结果
    // 并打印出这个结果，结果保留三位小数
    printf("%.3lf", (double)GetMax(a, b, c) / ( GetMax(a + b, b, c) * GetMax(a, b, b + c)));
    return 0;
}
