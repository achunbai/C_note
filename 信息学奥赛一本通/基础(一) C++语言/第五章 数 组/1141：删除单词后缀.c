/*
1141：删除单词后缀

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 36483     通过数: 24956
【题目描述】
给定一个单词，如果该单词以er、ly或者ing后缀结尾， 则删除该后缀（题目保证删除后缀后的单词长度不为0）， 否则不进行任何操作。

【输入】
输入一行，包含一个单词（单词中间没有空格，每个单词最大长度为32）。

【输出】
输出按照题目要求处理后的单词。

【输入样例】
referer
【输出样例】
refer
*/
#include <stdio.h>
#include <string.h>

int main()
{
    char word[33];  // 定义一个字符数组，用于存储输入的单词
    scanf("%s", word);  // 从标准输入读取一个字符串
    int length = (int)strlen(word);  // 计算字符串的长度
    // 如果字符串的后三个字符是"ing"，则删除这三个字符
    if(strcmp(&word[length - 3], "ing") == 0)
    {
        word[length - 3] = 0;  // 将字符串的倒数第三个字符设置为'\0'，即字符串结束标志
    }
    // 如果字符串的后两个字符是"er"或"ly"，则删除这两个字符
    else if(strcmp(&word[length - 2], "er") == 0 || strcmp(&word[length - 2], "ly") == 0)
    {
        word[length - 2] = 0;  // 将字符串的倒数第二个字符设置为'\0'，即字符串结束标志
    }
    printf("%s\n", word);  // 输出处理后的字符串
    return 0;
}