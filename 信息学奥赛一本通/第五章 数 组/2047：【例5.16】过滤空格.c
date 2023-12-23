/*
2047：【例5.16】过滤空格

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 38097     通过数: 24557
【题目描述】
过滤多余的空格。一个句子中也许有多个连续空格，过滤掉多余的空格，只留下一个空格。

【输入】
一行，一个字符串（长度不超过200
），句子的头和尾都没有空格。

【输出】
过滤之后的句子。

【输入样例】
Hello      world.This is    c language.
【输出样例】
Hello world.This is c language.
*/
#include <stdio.h>
#include <string.h>

int main()
{
    // 定义一个字符数组，用于存储输入的字符串
    char str[201];
    // 使用gets函数读取输入数据
    gets(str);
    int i, x = 0;
    // 定义一个字符变量，用于存储上一个字符
    char prev_char = ' ';

    // 遍历字符串中的每个字符
    for (i = 0; str[i]; i++)
    {
        // 如果当前字符和上一个字符不都是空格
        if (!(str[i] == ' ' && prev_char == ' '))
        {
            // 将当前字符添加到结果字符串中
            str[x++] = str[i];
        }
        // 更新上一个字符
        prev_char = str[i];
    }
    // 在结果字符串的末尾添加空字符
    str[x] = '\0';
    // 打印结果字符串
    printf(str);
    return 0;
}
