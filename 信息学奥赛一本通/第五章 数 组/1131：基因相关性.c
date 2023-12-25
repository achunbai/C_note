/*
1131：基因相关性

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 63661     通过数: 33670
【题目描述】
为了获知基因序列在功能和结构上的相似性，经常需要将几条不同序列的DNA进行比对，以判断该比对的DNA是否具有相关性。

现比对两条长度相同的DNA序列。定义两条DNA序列相同位置的碱基为一个碱基对，如果一个碱基对中的两个碱基相同的话，则称为相同碱基对。接着计算相同碱基对占总碱基对数量的比例，如果该比例大于等于给定阈值时则判定该两条DNA序列是相关的，否则不相关。

【输入】
有三行，第一行是用来判定出两条DNA序列是否相关的阈值，随后2行是两条DNA序列(长度不大于500)。

【输出】
若两条DNA序列相关，则输出“yes”，否则输出“no”。

【输入样例】
0.85
ATCGCCGTAAGTAACGGTTTTAAATAGGCC
ATCGCCGGAAGTAACGGTCTTAAATAGGCC
【输出样例】
yes
*/
#include <stdio.h>
#include <string.h>

int main()
{
    char dna1[501], dna2[501];  // 定义两个字符数组用于存储输入的DNA序列
    double threshold;  // 定义一个浮点数用于存储输入的阈值
    int count = 0, length;  // count用于计算两个DNA序列中相同的碱基对的数量，length用于存储DNA序列的长度
    scanf("%lf %s %s", &threshold, dna1, dna2);  // 从标准输入读取阈值和两个DNA序列
    length = strlen(dna1);  // 使用strlen函数计算DNA序列的长度
    for (int i = 0; i < length; i++)  // 遍历每个碱基对
    {
        if (dna1[i] == dna2[i])  // 如果两个DNA序列在同一位置的碱基对相同
        {
            count++;  // count增加1
        }
    }
    if (threshold <= (double)count / length)  // 如果阈值小于或等于相同的碱基对的数量除以DNA序列的长度
    {
        printf("yes");  // 打印"yes"
    }
    else
    {
        printf("no");  // 否则，打印"no"
    }
    return 0;  // 函数返回0，表示程序正常结束
}