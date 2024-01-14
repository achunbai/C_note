/*
1163：阿克曼(Ackmann)函数

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 33265     通过数: 26836
【题目描述】
阿克曼(Ackmann)函数A(m，n)
中，m，n
定义域是非负整数(m≤3,n≤10)
，函数值定义为：

akm(m,n)=⎧⎩⎨⎪⎪n+1akm(m−1,1)akm(m−1,akm(m,n−1))(m=0时)(m>0,n=0时)(m,n>0时)
【输入】
输入m
和n
。

【输出】
函数值。

【输入样例】
2 3
【输出样例】
9
*/
#include <stdio.h>

// 阿克曼函数的实现
int SolveAckmannFunction(int m, int n)
{
    // 如果m为0，直接返回n+1
    if(m == 0)
    {
        return n + 1;
    }
    else
    {
        // 如果m大于0且n为0，递归调用阿克曼函数，m减1，n变为1
        if(m > 0 && n == 0)
        {
            return SolveAckmannFunction(m - 1, 1);
        }
        // 如果m和n都大于0，递归调用阿克曼函数，m减1，n变为阿克曼函数的值
        else if(m > 0 && n > 0)
        {
            return SolveAckmannFunction(m - 1, SolveAckmannFunction(m, n - 1));
        }
        // 其他情况返回-1，实际上这种情况不会发生，因为题目已经限定了m和n的取值范围
        else
        {
            return -1;
        }
    }
}

int main()
{
    int m, n;
    // 读取输入的m和n
    scanf("%d %d", &m, &n);
    // 计算阿克曼函数的值并打印
    printf("%d\n", SolveAckmannFunction(m, n));
    return 0;
}
