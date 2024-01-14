/*
1412：二进制分类

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 24936     通过数: 16488
【题目描述】
若将一个正整数化为二进制数，在此二进制数中，我们将数字1
的个数多于数字0
的个数的这类二进制数称为A
类数，否则就称其为B
类数。

例如：

(13)10=(1101)2
，其中1
的个数为3
，0
的个数为1
，则称此数为A
类数；

(10)10=(1010)2
，其中1
的个数为2
，0
的个数也为2
，称此数为B
类数；

(24)10=(11000)2
，其中1
的个数为2
，0
的个数为3
，则称此数为B
类数；

程序要求：求出1∼1000
之中（包括1
与1000
），全部A
、B
两类数的个数。

【输入】
(无）

【输出】
一行，包含两个整数，分别是A
类数和B
类数的个数，中间用单个空格隔开。

【输入样例】
(无）
【输出样例】
(无）
*/
#include <stdio.h>
#include <math.h>

// 计算一个数的二进制表示中1的个数
int GetBinaryOneNum(int Num)
{
    int cnt = 0;
    while (Num)
    {
        Num &= (Num - 1);  // 将Num和Num-1做位与运算
        cnt++;  // 计数
    }
    return cnt;  // 返回1的个数
}

int main()
{
    int TypeA = 0, TypeB = 0, OneNum, ZeroNum;
    for (int i = 1; i <= 1000; i++)  // 遍历1到1000之间的所有数
    {
        OneNum = GetBinaryOneNum(i);  // 计算i的二进制表示中1的个数
        ZeroNum = (int)ceil(log2(i+1)) - OneNum;  // 计算i的二进制表示中0的个数
        if(OneNum > ZeroNum)  // 如果1的个数多于0的个数
        {
            TypeA++;  // A类数的个数加1
        }
        else if(OneNum <= ZeroNum)  // 如果0的个数多于或等于1的个数
        {
            TypeB++;  // B类数的个数加1
        }
    }
    printf("%d %d\n", TypeA, TypeB);  // 输出A类数和B类数的个数
    return 0;
}
