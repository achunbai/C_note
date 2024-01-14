/*
1400：统计单词数

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 46774     通过数: 16055
【题目描述】
一般的文本编辑器都有查找单词的功能，该功能可以快速定位特定单词在文章中的位置，有的还能统计出特定单词在文章中出现的次数。

现在，请你编程实现这一功能，具体要求是：给定一个单词，请你输出它在给定的文章中出现的次数和第一次出现的位置。注意：匹配单词时，不区分大小写，但要求完全匹配，即给定单词必须与文章中的某一独立单词在不区分大小写的情况下完全相同（参见样例1），如果给定单词仅是文章中某一单词的一部分则不算匹配（参见样例2）。

【输入】
第 1 行为一个字符串，其中只含字母，表示给定单词；

第 2 行为一个字符串，其中只可能包含字母和空格，表示给定的文章。

【输出】
只有一行，如果在文章中找到给定单词则输出两个整数，两个整数之间用一个空格隔开，分别是单词在文章中出现的次数和第一次出现的位置（即在文章中第一次出现时，单词首字母在文章中的位置，位置从0开始）；如果单词在文章中没有出现，则直接输出一个整数-1。

【输入样例】
To
to be or not to be is a question
【输出样例】
2 0
【提示】
样例输入:

样例 #2：

to
Did the Ottoman Empire lose its power at that time
样例输出:

样例 #2：

-1
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// 将字符串转换为小写
void Str_tolower(char* str)
{
    while(*str != '\0')
    {
        *str = tolower(*str);
        str++;
    }
}

int main()
{
    // 分配内存存储单词和文章
    char *str = (char*)calloc(1000001, 1), *passage = (char*)calloc(1000001, 1), *p;
    // 从输入读取单词和文章
    fgets(str, 1000001, stdin);
    fgets(passage, 1000001, stdin);
    // 去除字符串末尾的换行符
    str[strcspn(str, "\n")] = 0;
    passage[strcspn(passage, "\n")] = 0;
    // 将单词和文章转换为小写
    Str_tolower(str);
    Str_tolower(passage);
    // 初始化单词出现次数和位置
    int cnt = 0, len = (int)strlen(str);
    long pos = -1;
    p = passage;
    // 在文章中查找单词
    while ((p = strstr(p, str)) != NULL)
    {
        // 检查单词是否为独立的单词
        if((p == passage || *(p - 1) == ' ') && (*(p + len) == ' ' || *(p + len) == '\0'))
        {
            // 如果是，增加计数器，并记录位置
            cnt++;
            if(pos == -1)
            {
                pos = p - passage;
            }
        }
        // 移动到下一个字符
        p++;
    }
    // 输出结果
    if(cnt > 0)
    {
        printf("%d %ld\n", cnt, pos);
    }
    else
    {
        printf("-1\n");
    }
    // 释放内存
    free(str);
    free(passage);
    return 0;
}
