/*
1053：最大数输出

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 87726     通过数: 62450
【题目描述】
输入三个整数，数与数之间以一个空格分开。 输出一个整数，即最大的整数。

【输入】
输入为一行，包含三个整数，数与数之间以一个空格分开。

【输出】
输出一行，包含一个整数，即最大的整数。

【输入样例】
10 20 56
【输出样例】
56
*/

/*
#include <stdio.h>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int max = a;
    if (b > max)
    {
        max = b;
    }
    if (c > max)
    {
        max = c;
    }
    printf("%d", max);
    return 0;
}
*/

#include <stdio.h>

int larger(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main() 
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d", larger(a, larger(b, c)));
}