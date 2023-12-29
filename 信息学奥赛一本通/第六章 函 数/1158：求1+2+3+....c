/*
1158：求1+2+3+...

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 55615     通过数: 45553
【题目描述】
用递归的方法求1+2+3+……+N
的值。

【输入】
输入N
。

【输出】
输出和。

【输入样例】
5
【输出样例】
15
*/
#include <stdio.h>

// 使用递归的方式计算1到num的所有整数之和
int getSum(int num)
{
    if(num == 1)  // 如果num等于1，那么返回1
        return num;
    else
        // 如果num大于1，那么返回num加上1到num-1的所有整数之和
        return num + getSum(num - 1);
}

int main()
{
    int n;
    scanf("%d", &n);  // 读取输入的n
    printf("%d", getSum(n));  // 调用getSum函数计算和，然后打印出这个和
    return 0;
}
