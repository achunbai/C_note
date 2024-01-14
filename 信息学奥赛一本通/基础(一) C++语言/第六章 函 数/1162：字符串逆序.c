/*
1162：字符串逆序

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 36989     通过数: 24262
【题目描述】
输入一串以‘！’结束的字符，按逆序输出。

【输入】
如题述。

【输出】
如题述。

【输入样例】
abc!
【输出样例】
cba
*/

/*
#include <stdio.h>

// 递归函数，用于逆序打印字符串
void ReversePrint()
{
    char c;
    scanf("%c", &c);
    if (c != '!')
    {
        ReversePrint();
        printf("%c", c);
    }
}

int main()
{
    ReversePrint();
    printf("\n");
    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 循环版本的字符串逆序打印函数
void ReversePrint(char* str)
{
    // 获取字符串长度
    int length = (int)strlen(str);
    // 从字符串末尾开始，向前遍历，打印每个字符
    for (int i = length - 2; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}

// 递归版本的字符串逆序打印函数
void ReversePrintRecursive(char* str)
{
    // 如果当前字符不是'!'，则递归处理下一个字符，然后打印当前字符
    if(*str != '!')
    {
        ReversePrintRecursive(str + 1);
        printf("%c", *str);
    }
}

int main()
{
    // 读取输入的字符串
    char str[1001];
    scanf("%s", str);
    // 调用循环版本的函数
    // ReversePrint(str);
    // 调用递归版本的函数
    ReversePrintRecursive(str);
    printf("\n");
    return 0;
}
