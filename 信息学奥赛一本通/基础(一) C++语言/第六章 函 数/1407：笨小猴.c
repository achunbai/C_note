/*
1407：笨小猴

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 48961     通过数: 19362
【题目描述】
笨小猴的词汇量很小，所以每次做英语选择题的时候都很头疼。但是他找到了一种方法，经试验证明，用这种方法去选择选项的时候选对的几率非常大！

这种方法的具体描述如下：假设maxn
是单词中出现次数最多的字母的出现次数，minn
是单词中出现次数最少的字母的出现次数，如果maxn−minn
是一个质数，那么笨小猴就认为这是个Lucky Word
，这样的单词很可能就是正确的答案。

【输入】
只有一行，是一个单词，其中只可能出现小写字母，并且长度小于100
。

【输出】
共两行，第一行是一个字符串，假设输入的的单词是Lucky Word
，那么输出“Lucky Word
”，否则输出“No Answer
”；

第二行是一个整数，如果输入单词是Lucky Word
，输出maxn−minn
的值，否则输出0
。

【输入样例】
error
【输出样例】
Lucky Word
2
【提示】
样例输入:

样例 #2：

olympic
样例输出:

样例 #2：

No Answer
0
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 获取质数的函数，返回一个数组，数组的索引是数字，值为1表示不是质数，值为0表示是质数
int *GetPrime(int MaxNum)
{
    int *Prime = (int*)calloc(MaxNum + 1, sizeof(int));
    Prime[0] = Prime[1] = 1;  // 0和1不是质数
    for (int i = 2; i <= MaxNum; i++)
    {
        for (int j = i + i; j <= MaxNum; j += i)
        {
            if(!Prime[j])
            {
                Prime[j] = 1;  // 标记非质数
            }
        }
    }
    return Prime;
}

// 获取LuckyValue的函数，LuckyValue是单词中出现次数最多的字母的出现次数和出现次数最少的字母的出现次数之差
int GetLuckyValue(char* word)
{
    int cnt[128] = { 0 }, MaxNum = 0, MinNum = 100;
    for (int i = 0; word[i] != '\0'; i++)
    {
        cnt[word[i]]++;  // 统计每个字母的出现次数
    }
    for (int i = 0; i < 128; i++)
    {
        if(cnt[i])
        {
            if(MaxNum < cnt[i])
            {
                MaxNum = cnt[i];  // 更新出现次数最多的字母的出现次数
            }
            if(MinNum > cnt[i])
            {
                MinNum = cnt[i];  // 更新出现次数最少的字母的出现次数
            }
        }
    }
    return MaxNum - MinNum;  // 返回LuckyValue
}

int main()
{
    char word[101];
    scanf("%s", word);
    int *Prime = GetPrime(100), LuckyValue = GetLuckyValue(word);
    if(!Prime[LuckyValue])  // 如果LuckyValue是质数
    {
        printf("Lucky Word\n%d\n", LuckyValue);
    }
    else  // 如果LuckyValue不是质数
    {
        printf("No Answer\n0\n");
    }
    free(Prime);  // 释放内存
    return 0;
}
