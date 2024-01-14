/*
1136：密码翻译

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 72299     通过数: 30920
【题目描述】
在情报传递过程中，为了防止情报被截获，往往需要对情报用一定的方式加密，简单的加密算法虽然不足以完全避免情报被破译，但仍然能防止情报被轻易的识别。我们给出一种最简的的加密方法，对给定的一个字符串，把其中从a-y，A-Y的字母用其后继字母替代，把z和Z用a和A替代，其他非字母字符不变，则可得到一个简单的加密字符串。

【输入】
输入一行，包含一个字符串，长度小于80个字符。

【输出】
输出每行字符串的加密字符串。

【输入样例】
Hello! How are you!
【输出样例】
Ifmmp! Ipx bsf zpv!
*/
/*
#include <stdio.h>
int main()
{
    char str[81];  // 定义一个字符数组用于存储输入的字符串
    fgets(str, 81, stdin);  // 从标准输入读取一行字符串
    for (int i = 0; str[i] != 0; i++)  // 遍历字符串中的每个字符
    {
        if (str[i] >= 'a' && str[i] <= 'y')  // 如果字符是小写字母且不是z
        {
            str[i]++;  // 将其替换为其后继字母
        }
        else if (str[i] == 'z')  // 如果字符是z
        {
            str[i] = 'a';  // 将其替换为a
        }
        else if (str[i] >= 'A' && str[i] <= 'Y')  // 如果字符是大写字母且不是Z
        {
            str[i]++;  // 将其替换为其后继字母
        }
        else if (str[i] == 'Z')  // 如果字符是Z
        {
            str[i] = 'A';  // 将其替换为A
        }
    }
    printf("%s", str);  // 打印替换后的字符串
    return 0;
}
*/
/*
#include <stdio.h>
int main()
{
    char input[81];  // 定义一个字符数组用于存储输入的字符串
    fgets(input, 81, stdin);  // 从标准输入读取一行字符串
    for (int i = 0; input[i] != 0; i++)  // 遍历字符串中的每个字符
    {
        // 如果字符是英文字母（不包括Z和z），将其ASCII码值加1，即将其替换为下一个字母
        if ((input[i] >= 'A' && input[i] < 'Z') || (input[i] >= 'a' && input[i] < 'z'))
        {
            input[i] += 1;
        }
        // 如果字符是Z，将其替换为A
        else if (input[i] == 'Z')
        {
            input[i] = 'A';
        }
        // 如果字符是z，将其替换为a
        else if (input[i] == 'z')
        {
            input[i] = 'a';
        }
    }
    printf("%s", input);  // 使用"%s"格式说明符来安全地打印字符串
    return 0;
}
*/
#include <stdio.h>

int main()
{
    char input[81];  // 定义一个字符数组用于存储输入的字符串
    fgets(input, 81, stdin);  // 从标准输入读取字符串
    for (int i = 0; input[i] != '\0'; i++)  // 遍历字符串中的每个字符
    {
        // 如果字符是A到Y或a到y之间的字母
        if ((input[i] >= 'A' && input[i] < 'Z') || (input[i] >= 'a' && input[i] < 'z'))
        {
            input[i] += 1;  // 字符向后移动一位
        }
        // 如果字符是Z或z
        else if (input[i] == 'Z' || input[i] == 'z')
        {
            input[i] -= 25;  // 字符向前移动25位，即变为A或a
        }
    }
    printf("%s", input);  // 打印处理后的字符串
    return 0;  // 函数返回0，表示程序正常结束
}