/*
1149：最长单词2

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 34953     通过数: 19557
【题目描述】
一个以‘.’结尾的简单英文句子，单词之间用空格分隔，没有缩写形式和其它特殊形式。

【输入】
一个以‘.’结尾的简单英文句子（长度不超过500），单词之间用空格分隔，没有缩写形式和其它特殊形式。

【输出】
该句子中最长的单词。如果多于一个，则输出第一个。

【输入样例】
I am a student of Peking University.
【输出样例】
University
*/
#include <stdio.h>

int main()
{
    int cnt = 0, maxp = 0, maxc = 0;  // cnt是当前单词的长度，maxp是最长单词的位置，maxc是最长单词的长度
    char sentence[502] = { 0 };  // 句子

    fgets(sentence, 502, stdin);  // 读取句子

    // 遍历句子中的每个字符
    for(int i = 0; sentence[i] != '\n' && sentence[i] != 0; i++)
    {
        // 如果当前字符是空格或句号
        if(sentence[i] == ' ' || sentence[i] == '.')
        {
            // 检查当前单词的长度是否是最长的
            if(cnt > maxc)
            {
                maxc = cnt;  // 更新最长单词的长度
                maxp = i - cnt;  // 更新最长单词的位置
            }
            cnt = 0;  // 重置当前单词的长度
        }
        else
            cnt++;  // 增加当前单词的长度
    }

    // 打印出最长的单词
    printf("%.*s\n", maxc, &sentence[maxp]);

    return 0;
}