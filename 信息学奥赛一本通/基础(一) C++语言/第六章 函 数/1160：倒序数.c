/*
1160：倒序数

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 48406     通过数: 33501
【题目描述】
输入一个非负整数，输出这个数的倒序数。例如输入123，输出321。

【输入】
输入一个非负整数(保证个位不为零）。

【输出】
输出倒序的数。

【输入样例】
123
【输出样例】
321
*/
#include <stdio.h>

// 循环版本，用于计算倒序数
int ReverseNum(int num)
{
    int ReversedNum = 0;
    // 当num不为0时，继续循环
    while (num)
    {
        // 将num的最后一位添加到ReversedNum的末尾
        ReversedNum = ReversedNum * 10 + num % 10;
        // 去掉num的最后一位
        num /= 10;
    }
    return ReversedNum;
}

// 递归版本1，用于计算倒序数
int ReverseNumRecursive(int num, int ReversedNum)
{
    // 当num为0时，返回ReversedNum
    if(num == 0)
    {
        return ReversedNum;
    }
    else
    {
        // 将num的最后一位添加到ReversedNum的末尾，然后去掉num的最后一位
        return ReverseNumRecursive(num / 10, ReversedNum * 10 + num % 10);
    }
}

// 递归版本2，直接打印倒序数
void ReverseNumRecursive2(int num)
{
    // 打印num的最后一位
    printf("%d", num % 10);
    // 如果num的位数大于1，继续递归
    if (num >= 10)
    {
        ReverseNumRecursive2(num / 10);
    }
}

int main()
{
    int Num, ReversedNum;
    // 输入一个数字
    scanf("%d", &Num);
    // 计算倒序数
    ReversedNum = ReverseNum(Num);
    // 打印倒序数
    printf("%d\n", ReversedNum);
    return 0;
}


