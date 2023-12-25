/*
1140：验证子串

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 51980     通过数: 24529
【题目描述】
输入两个字符串，验证其中一个串是否为另一个串的子串。

【输入】
输入两个字符串， 每个字符串占一行，长度不超过200且不含空格。

【输出】
若第一个串s1是第二个串s2的子串，则输出(s1) is substring of (s2)

否则，若第二个串s2是第一个串s1的子串，输出(s2) is substring of (s1)

否则，输出 No substring。

【输入样例】
abc
dddncabca
【输出样例】
abc is substring of dddncabca
*/
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[201], str2[201];  // 定义两个字符数组用于存储输入的字符串
    scanf("%s %s", str1, str2);  // 从标准输入读取两个字符串
    // 使用strstr函数检查str2是否是str1的子串
    if (strstr(str1, str2) != NULL)
    {
        printf("%s is substring of %s", str2, str1);  // 如果是，打印结果
    }
    // 使用strstr函数检查str1是否是str2的子串
    else if (strstr(str2, str1) != NULL)
    {
        printf("%s is substring of %s", str1, str2);  // 如果是，打印结果
    }
    else
    {
        printf("No substring");  // 如果两个字符串都不是对方的子串，打印"No substring"
    }
    return 0;
}