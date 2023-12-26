/*
1150：求正整数2和n之间的完全数

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 71661     通过数: 44368
【题目描述】
求正整数2
和n
之间的完全数(一行一个数)。

完全数：因子之和等于它本身的自然数，如6=1+2+3
【输入】
输入n(n≤5000)
。

【输出】
一行一个数,按由小到大的顺序。

【输入样例】
7
【输出样例】
6
*/
#include <stdio.h>
#include <math.h>

// 计算一个数的所有因子之和
int getSum(int num)
{
    int sum = 1;  // 因子之和初始化为1，因为1是所有数的因子
    int sqrtNum = sqrt(num);  // 计算数的平方根，用于优化循环
    for (int i = 2; i <= sqrtNum; i++)
    {
        if(num % i == 0)
        {
            sum += i;  // 加上因子i
            if(i != num / i)  // 避免平方根被加两次
                sum += num / i;  // 加上配对的因子
        }
    }
    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);  // 读取输入的n
    for(int i = 2; i <= n; i++)  // 遍历2到n之间的所有数
    {
        if(i == getSum(i))  // 如果一个数等于它的所有因子之和
            printf("%d\n", i);  // 打印这个数
    }
    return 0;
}