/*
1133：输出亲朋字符串

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 43733     通过数: 28226
【题目描述】
编写程序，求给定字符串s的亲朋字符串s1。

   亲朋字符串s1定义如下：给定字符串s的第一个字符的ASCII值加第二个字符的ASCII值，得到第一个亲朋字符； 给定字符串s的第二个字符的ASCII值加第三个字符的ASCII值，得到第二个亲朋字符；依此类推，直到给定字符串s的倒数第二个字符。亲朋字符串的最后一个字符由给定字符串s的最后一个字符ASCII值加s的第一个字符的ASCII值。

【输入】
输入一行，一个长度大于等于2，小于等于100的字符串。字符串中每个字符的ASCII值不大于63。

【输出】
输出一行，为变换后的亲朋字符串。输入保证变换后的字符串只有一行。

【输入样例】
1234
【输出样例】
cege
*/
#include <stdio.h>
#include <string.h>

int main()
{
    char input[101], result[101] = " ";  // 定义两个字符数组，input用于存储输入的字符串，result用于存储结果字符串
    int length;  // 定义一个整数length用于存储字符串的长度
    scanf("%s", input);  // 从标准输入读取字符串
    length = strlen(input);  // 计算字符串的长度
    result[length - 1] = input[0] + input[length - 1];  // 计算结果字符串的最后一个字符
    for (int i = 0; i < length - 1; i++)  // 遍历输入字符串的每个字符（除了最后一个）
    {
        result[i] = input[i] + input[i + 1];  // 计算结果字符串的每个字符
    }
    printf(result);  // 打印结果字符串
    return 0;
}