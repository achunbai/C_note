/*
1406：单词替换

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 25332     通过数: 14883
【题目描述】
输入一个字符串，以回车结束（字符串长度≤200）。该字符串由若干个单词组成，单词之间用一个空格隔开，所有单词区分大小写。现需要将其中的某个单词替换成另一个单词，并输出替换之后的字符串。

【输入】
第1行是包含多个单词的字符串 s；

第2行是待替换的单词a(长度 ≤ 100)；

第3行是a将被替换的单词b(长度 ≤ 100)。

s,a,b最前面和最后面都没有空格。

【输出】
输出只有 1 行，将s中所有单词a替换成b之后的字符串。

【输入样例】
You want someone to help you
You
I
【输出样例】
I want someone to help you
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// 单词替换函数
char* WordReplace(char* String, const char* Origin, const char* Replace, const int ResultLen)
{
    // 初始化结果字符串和开始、结束位置指针
    char *Result = (char*)calloc(ResultLen, sizeof(char)), *start = String, *end = String;
    int OriginLen = (int)strlen(Origin);
    // 在字符串中查找待替换的单词
    while ((end = strstr(start, Origin)) != NULL)
    {
        // 如果找到了待替换的单词，并且它前后都是空格（或者是字符串的开始或结束）
        if((end == String || *(end - 1) == ' ') && (*(end + OriginLen) == ' ' || *(end + OriginLen) == '\0'))
        {
            // 将待替换单词前的字符串复制到结果字符串
            strncat(Result, start, end - start);
            // 将替换词复制到结果字符串
            strcat(Result, Replace);
            // 更新开始位置
            start = end + OriginLen;
        }
        else
        {
            // 如果待替换的单词不满足条件，跳过这个位置
            start = end + 1;
        }
    }
    // 将剩余的字符串复制到结果字符串
    strcat(Result, start);
    return Result;
}

int main()
{
    // 初始化字符串和待替换的单词
    char *str = (char*)calloc(201, sizeof(char)), *w1 = (char*)calloc(101, sizeof(char)), *w2 = (char*)calloc(101, sizeof(char));
    // 读取字符串和待替换的单词
    fgets(str, 201, stdin);
    str[strcspn(str, "\n")] = '\0';
    scanf("%s %s", w1, w2);
    // 调用单词替换函数
    char *Result = WordReplace(str, w1, w2, 201);
    // 输出替换后的字符串
    printf("%s\n", Result);
    // 释放内存
    free(str);
    free(w1);
    free(w2);
    free(Result);
    return 0;
}
