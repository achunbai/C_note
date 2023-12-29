/*
1144：单词翻转

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 47407     通过数: 20806
【题目描述】
输入一个句子(一行)，将句子中的每一个单词翻转后输出。

【输入】
只有一行，为一个字符串，不超过500个字符。单词之间以空格隔开。

【输出】
翻转每一个单词后的字符串，单词之间的空格需与原文一致。

【输入样例】
hello world
【输出样例】
olleh dlrow
*/
/*
#include <stdio.h>
#include <string.h>

void stringReverse(char* start, char* end)
{
    while (start < end)
    {
        char tmp = *start;
        *start = *end;
        *end = tmp;
        start++;
        end--;
    }
}

int main()
{
    char str[501], *start = str, *end;
    gets(str);
    for (int i = 0; i <= (int)strlen(str); i++)
    {
        if(str[i] == 0 || str[i] == ' ')
        {
            end = &str[i] - 1;
            stringReverse(start, end);
            start = &str[i] + 1;
        }
    }
    puts(str);
    return 0;
}
*/

/*
#include <stdio.h>
#include <string.h>

// 定义一个函数，用于反转字符串
void stringReverse(char* start, char* end)
{
    while (start < end)  // 当开始位置小于结束位置时，继续反转
    {
        char tmp = *start;  // 交换开始位置和结束位置的字符
        *start = *end;
        *end = tmp;
        start++;  // 更新开始位置
        end--;  // 更新结束位置
    }
}

int main()
{
    char str[501];  // 存储输入的字符串
    char *start = str;  // 指向每个单词的开始
    char *end;  // 指向每个单词的结束

    gets(str);  // 读取输入的字符串
    int len = (int)strlen(str);  // 计算字符串的长度

    for (int i = 0; i <= len; i++)  // 遍历字符串
    {
        if(str[i] == 0 || str[i] == ' ')  // 如果遇到空格或字符串结束，说明一个单词结束
        {
            end = &str[i] - 1;  // 更新单词的结束位置
            stringReverse(start, end);  // 反转单词
            start = &str[i] + 1;  // 更新单词的开始位置
        }
    }
    puts(str);  // 打印反转后的字符串
    return 0;
}
*/

/*
#include <stdio.h>
#include <string.h>

// 定义一个函数，用于反转字符串
void stringReverse(char* start, char* end)
{
    while (start < end)  // 当开始位置小于结束位置时，继续反转
    {
        char tmp = *start;  // 交换开始位置和结束位置的字符
        *start = *end;
        *end = tmp;
        start++;  // 更新开始位置
        end--;  // 更新结束位置
    }
}

int main()
{
    char str[501];  // 存储输入的字符串
    char *start = str;  // 指向每个单词的开始
    char *end;  // 指向每个单词的结束

    scanf("%[^\n]", str);  // 使用scanf代替gets，读取一行输入，直到遇到换行符

    int len = strlen(str);  // 计算字符串的长度

    for (int i = 0; i <= len; i++)  // 遍历字符串
    {
        if(str[i] == 0 || str[i] == ' ')  // 如果遇到空格或字符串结束，说明一个单词结束
        {
            end = &str[i] - 1;  // 更新单词的结束位置
            stringReverse(start, end);  // 反转单词
            start = &str[i] + 1;  // 更新单词的开始位置
        }
    }
    puts(str);  // 打印反转后的字符串
    return 0;
}
*/

#include <stdio.h>
#include <string.h>

// 定义一个函数，用于反转字符串
void stringReverse(char* start, char* end)
{
    while (start < end)  // 当开始位置小于结束位置时，继续反转
    {
        char tmp = *start;  // 交换开始位置和结束位置的字符
        *start = *end;
        *end = tmp;
        start++;  // 更新开始位置
        end--;  // 更新结束位置
    }
}

int main()
{
    char str[501];  // 存储输入的字符串
    char *start = str;  // 指向每个单词的开始
    char *end;  // 指向每个单词的结束

    fgets(str, 501, stdin);  // 使用fgets读取一行输入

    int len = (int)strlen(str);  // 计算字符串的长度

    for (int i = 0; i <= len; i++)  // 遍历字符串
    {
        // 如果遇到空格、换行符或字符串结束，说明一个单词结束
        if(str[i] == 0 || str[i] == '\n' || str[i] == ' ')
        {
            end = &str[i] - 1;  // 更新单词的结束位置
            stringReverse(start, end);  // 反转单词
            start = &str[i] + 1;  // 更新单词的开始位置
        }
    }
    puts(str);  // 打印反转后的字符串
    return 0;
}
