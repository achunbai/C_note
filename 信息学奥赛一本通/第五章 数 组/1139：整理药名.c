/*
1139：整理药名

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 49376     通过数: 25824
【题目描述】
医生在书写药品名的时候经常不注意大小写，格式比较混乱。现要求你写一个程序将医生书写混乱的药品名整理成统一规范的格式，即药品名的第一个字符如果是字母要大写，其他字母小写。如将ASPIRIN、aspirin整理成Aspirin。

【输入】
第一行一个数字n，表示有n个药品名要整理，n不超过100。

接下来n行，每行一个单词，长度不超过20，表示医生手书的药品名。药品名由字母、数字和-组成。

【输出】
n行，每行一个单词，对应输入的药品名的规范写法。

【输入样例】
4
AspiRin
cisapride
2-PENICILLIN
Cefradine-6
【输出样例】
Aspirin
Cisapride
2-penicillin
Cefradine-6
*/
#include <stdio.h>
#include <ctype.h>

int main()
{
    char input[100][21];  // 定义一个二维字符数组用于存储输入的字符串
    int n;  // 定义一个整数n用于存储输入的字符串数量
    scanf("%d", &n);  // 从标准输入读取字符串数量
    for (int i = 0; i < n; i++)  // 遍历每个字符串
    {
        scanf("%s", input[i]);  // 从标准输入读取一个字符串
        input[i][0] = toupper(input[i][0]);  // 将字符串的第一个字符转换为大写
        for (int j = 1; input[i][j] != 0 ; j++)  // 遍历字符串的每个字符，除了第一个字符
        {
            input[i][j] = tolower(input[i][j]);  // 将字符转换为小写
        }
    }
    for (int i = 0; i < n; i++)  // 遍历每个字符串
    {
        printf("%s\n", input[i]);  // 打印字符串
    }
    return 0;
}