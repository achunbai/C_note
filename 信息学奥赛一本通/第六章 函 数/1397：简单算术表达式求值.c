/*
1397：简单算术表达式求值

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 33926     通过数: 24567
【题目描述】
两位正整数的简单算术运算（只考虑整数运算），算术运算为：

+，加法运算；

-，减法运算；

*，乘法运算；

/，整除运算；

%，取余运算。

算术表达式的格式为（运算符前后可能有空格）：

运算数 运算符 运算数

请输出相应的结果。

【输入】
一行算术表达式。

【输出】
整型算数运算的结果（结果值不一定为2位数，可能多于2位或少于2位）。

【输入样例】
32+64
【输出样例】
96
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 移除字符串中的空格和换行符
void RemoveSpace(char* str)
{
    if(str == NULL)
        return;
    else
    {
        int len = (int)strlen(str), j = 0;
        for(int i = 0; i < len; i++)
            if(str[i] != ' ' && str[i] != '\n')
                str[j++] = str[i];
        str[j] = 0;
    }
}

// 将算术表达式转换为一个数组，数组中的元素是数字和运算符
int* ArithmeticExpressionToArry(char* str)
{
    int* arr = (int*)calloc(1001, sizeof(int)), i = 0;
    char* start = str, *end = str, num[101];
    while(*str != 0)
    {
        if(*str >= '0' && *str <= '9')
            str++;
        else
        {
            end = str;
            strncpy(num, start, end - start);
            num[end - start] = '\0';  // 添加'\0'字符
            arr[i++] = atoi(num);
            arr[i++] = *str;
            start = str + 1;
            str++;
        }
    }
    strncpy(num, start, str - start);
    num[str - start] = '\0';  // 添加'\0'字符
    arr[i++] = atoi(num);  // 在循环内部处理最后一个数字
    arr[i] = -12345678;
    return arr;
}

// 从数组中移除一些元素
void ArrayRemove(int* arr, int start, int num)
{
    for (int i = start; arr[i] != -12345678; i++)
    {
        arr[i] = arr[i + num];
    }
}

// 计算数组表示的表达式的结果
int GetResult(int* arr)
{
    for (int i = 1; arr[i] != -12345678; i += 2)
    {
        if(arr[i] == '*')
        {
            arr[i - 1] *= arr[i + 1];
            ArrayRemove(arr, i, 2);
        }
        else if(arr[i] == '/')
        {
            arr[i - 1] /= arr[i + 1];
            ArrayRemove(arr, i, 2);
        }
        else if(arr[i] == '%')
        {
            arr[i - 1] %= arr[i + 1];
            ArrayRemove(arr, i, 2);
        }
    }
    for (int i = 1; arr[i] != -12345678; i += 2)
    {
        if(arr[i] == '+')
        {
            arr[i - 1] += arr[i + 1];
            ArrayRemove(arr, i, 2);
        }
        else if(arr[i] == '-')
        {
            arr[i - 1] -= arr[i + 1];
            ArrayRemove(arr, i, 2);
        }
    }
    return arr[0];
}

int main()
{
    char str[1001];
    int* arr;
    fgets(str, 1001, stdin);
    RemoveSpace(str);
    arr = ArithmeticExpressionToArry(str);
    printf("%d\n", GetResult(arr));
    free(arr);
    return 0;
}