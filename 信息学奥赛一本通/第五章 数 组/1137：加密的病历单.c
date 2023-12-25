/*
1137：加密的病历单

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 52301     通过数: 25998
【题目描述】
小英是药学专业大三的学生，暑假期间获得了去医院药房实习的机会。

在药房实习期间，小英扎实的专业基础获得了医生的一致好评，得知小英在计算概论中取得过好成绩后，主任又额外交给她一项任务，解密抗战时期被加密过的一些伤员的名单。

经过研究，小英发现了如下加密规律(括号中是一个“原文 -> 密文”的例子)

1.原文中所有的字符都在字母表中被循环左移了三个位置（dec  -> abz）

2.逆序存储（abcd -> dcba ）

3.大小写反转（abXY -> ABxy）

【输入】
一个加密的字符串。(长度小于50且只包含大小写字母)

【输出】
输出解密后的字符串。

【输入样例】
GSOOWFASOq
【输出样例】
Trvdizrrvj
*/
#include <stdio.h>
#include <string.h>

// 函数：反转字符串
void string_reverse(char* start, char* end)
{
    char tmp;
    // 当开始指针小于结束指针时，交换两个指针所指向的字符
    while (start < end)
    {
        tmp = *start;
        *start = *end;
        *end = tmp;
        start++;
        end--;
    }
}

// 函数：反转字符大小写
void case_reverse(char* start, char* end)
{
    // 当开始指针小于结束指针时，反转指针所指向的字符的大小写
    while (start < end)
    {
        // 如果字符是大写字母，将其转换为小写字母
        if (*start >= 'A' && *start <= 'Z')
        {
            *start += 32;
        }
        // 如果字符是小写字母，将其转换为大写字母
        else if (*start >= 'a' && *start <= 'z')
        {
            *start -= 32;
        }
        start++;
    }
}

int main()
{
    char input[51];  // 定义一个字符数组用于存储输入的字符串
    fgets(input, 51, stdin);  // 从标准输入读取一行字符串
    int length = strlen(input);  // 存储字符串长度
    string_reverse(input, input + length - 2);  // 反转字符串
    case_reverse(input, input + length - 1);  // 反转字符大小写
    for (int i = 0; input[i] != 0; i++)  // 遍历字符串中的每个字符
    {
        // 如果字符是英文字母（不包括X、Y、Z、x、y、z），将其ASCII码值加3，即将其替换为后面的第3个字母
        if ((input[i] >= 'A' && input[i] < 'X') || (input[i] >= 'a' && input[i] < 'x'))
        {
            input[i] += 3;
        }
        // 如果字符是X、Y、Z、x、y、z，将其ASCII码值减23，即将其替换为前面的第23个字母
        else if ((input[i] >= 'X' && input[i] < 'a') || (input[i] >= 'x'))
        {
            input[i] -= 23;
        }
    }
    printf("%s", input);  // 使用"%s"格式说明符来安全地打印字符串
    return 0;
}
