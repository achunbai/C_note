/*
2048：【例5.18】串排序

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 31581     通过数: 16306
【题目描述】
对给定的n(1≤n≤20)
个国家名（国家名字长度不超过20
），按其字母的顺序输出。

【输入】
第一行为国家的个数n
；

以下n
行为国家的名字。

【输出】
n
行，排序后的国名。

【输入样例】
3
Korea
China
Japan
【输出样例】
China
Japan
Korea
*/
#include <stdio.h>
#include <string.h>

int main()
{
    // 定义n，countries二维字符数组，order字符指针数组
    int n;
    char countries[20][21], *order[20];
    // 从标准输入读取n的值
    scanf("%d", &n);
    // 读取n个字符串，存储在countries二维字符数组中，并将order数组的每个元素指向对应的字符串
    for (int i = 0; i < n; i++)
    {
        order[i] = countries[i];
        scanf("%s", countries[i]);
    }
    // 使用冒泡排序算法对字符串进行排序
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            // 如果order[j]指向的字符串大于order[j + 1]指向的字符串，交换两个指针
            if (strcmp(order[j], order[j + 1]) > 0)
            {
                char* temp = order[j];
                order[j] = order[j + 1];
                order[j + 1] = temp;
            }
        }
    }
    // 输出排序后的字符串
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", order[i]);
    }
    return 0;
}