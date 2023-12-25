/*
1134：合法C标识符查

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 65366     通过数: 25515
【题目描述】
给定一个不包含空白符的字符串，请判断是否是C语言合法的标识符号(注：题目保证这些字符串一定不是C语言的保留字)。

C语言标识符要求：

1.非保留字；

2.只包含字母、数字及下划线（“_”）。

3.不以数字开头。

【输入】
一行，包含一个字符串，字符串中不包含任何空白字符，且长度不大于20。

【输出】
一行，如果它是C语言的合法标识符，则输出yes，否则输出no。

【输入样例】
RKPEGX9R;TWyYcp
【输出样例】
no
*/
#include <stdio.h>
#include <string.h>

// C语言保留字
char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "int", "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
};

int main()
{
    char str[21];  // 定义一个字符数组用于存储输入的字符串
    scanf("%s", str);  // 从标准输入读取一个字符串

    // 检查是否是C语言保留字
    for (int i = 0; i < sizeof(keywords) / sizeof(char *); i++) {
        if (strcmp(str, keywords[i]) == 0) {
            printf("no");  // 如果是保留字，打印"no"
            return 0;  // 结束程序
        }
    }

    // 检查是否是合法的C语言标识符
    if (str[0] >= '0' && str[0] <= '9')  // 如果字符串的第一个字符是数字
    {
        printf("no");  // 打印"no"
        return 0;  // 结束程序
    }
    for (int i = 0; str[i] != 0; i++)  // 遍历字符串中的每个字符
    {
        if (!((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == '_'))  // 如果字符不是数字、字母或下划线
        {
            printf("no");  // 打印"no"
            return 0;  // 结束程序
        }
    }
    printf("yes");  // 如果字符串是C语言合法的标识符，打印"yes"
    return 0;
}