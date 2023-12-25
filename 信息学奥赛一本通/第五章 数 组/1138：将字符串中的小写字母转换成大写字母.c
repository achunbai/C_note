/*
1138：将字符串中的小写字母转换成大写字母

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 68555     通过数: 31537
【题目描述】
给定一个字符串，将其中所有的小写字母转换成大写字母。

【输入】
输入一行，包含一个字符串（长度不超过100，可能包含空格）。

【输出】
输出转换后的字符串。

【输入样例】
helloworld123Ha
【输出样例】
HELLOWORLD123HA
*/
#include <stdio.h>
#include <ctype.h>

int main()
{
    char input[101];  // 定义一个字符数组用于存储输入的字符串
    fgets(input, 101, stdin);  // 从标准输入读取一行字符串
    for (int i = 0; input[i] != 0; i++)  // 遍历字符串中的每个字符
    {
        input[i] = toupper(input[i]);  // 使用toupper函数将字符转换为大写
    }
    printf("%s", input);  // 打印转换为大写后的字符串
    return 0;
}