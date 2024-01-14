/*
1143：最长最短单词

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 67679     通过数: 21443
【题目描述】
输入1行句子(不多于200个单词，每个单词长度不超过100)，只包含字母、空格和逗号。单词由至少一个连续的字母构成，空格和逗号都是单词间的间隔。

 试输出第1个最长的单词和第1个最短单词。

【输入】
一行句子。

【输出】
第1行，第一个最长的单词。

第2行，第一个最短的单词。

【输入样例】
I am studying Programming language C in Peking University
【输出样例】
Programming
I
【提示】
提示：

如果所有单词长度相同，那么第一个单词既是最长单词也是最短单词。
*/
#include <stdio.h>
#include <string.h>

int main()
{
    char str[20200];  // 存储输入的字符串
    char result[2][101] = { 0 };  // 存储最长和最短的单词
    char tmp[101] = { 0 };  // 临时存储每个单词
    char *start = str;  // 指向每个单词的开始
    char *end = str;  // 指向每个单词的结束
    int maxlen = 0;  // 最长单词的长度
    int minlen = 101;  // 最短单词的长度
    int tmplen;  // 每个单词的长度

    fgets(str, 20200, stdin);  // 读取输入的字符串

    for (int i = 0; i < strlen(str); i++)  // 遍历字符串
    {
        if(str[i] == ' ' || str[i] == ',' || str[i] == '\n')  // 如果遇到空格、逗号或换行符，说明一个单词结束
        {
            end = &str[i];  // 更新单词的结束位置
            strncpy(tmp, start, end - start);  // 将单词复制到临时数组
            tmp[end - start] = 0;  // 添加字符串结束标志
            tmplen = (int)strlen(tmp);  // 计算单词的长度

            if(maxlen < tmplen && tmplen)  // 如果单词的长度大于最长单词的长度
            {
                maxlen = tmplen;  // 更新最长单词的长度
                strcpy(result[0], tmp);  // 将单词复制到结果数组
            }
            if(minlen > tmplen && tmplen)  // 如果单词的长度小于最短单词的长度
            {
                minlen = tmplen;  // 更新最短单词的长度
                strcpy(result[1], tmp);  // 将单词复制到结果数组
            }
            start = &str[i] + 1;  // 更新单词的开始位置
        }
    }
    printf("%s\n%s", result[0], result[1]);  // 打印最长和最短的单词
    return 0;
}

