/*
1161：转进制

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 37638     通过数: 25381
【题目描述】
用递归算法将一个十进制数X转换成任意进制数M（M≤16）。

【输入】
一行两个数，第一个十进制数X，第二个为进制M。

【输出】
输出结果。

【输入样例】
31 16 ｛将十进制31转化为十六进制数｝
【输出样例】
1F
*/
/*
// 不用归递
#include <stdio.h>
#include <stdlib.h>

// 栈的结构体定义
typedef struct Stack
{
    int top;
    int capacity;
    int* array;
} Stack;

// 创建一个栈
Stack* createStack(int capacity)
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// 检查栈是否为空
int isEmpty(Stack* stack)
{
    return stack->top == -1;
}

// 向栈中压入一个元素
void push(Stack* stack, int item)
{
    stack->array[++stack->top] = item;
}

// 从栈中弹出一个元素
int pop(Stack* stack)
{
    return stack->array[stack->top--];
}

// 将一个十进制数转换为任意进制数
void ConvertToBase(int num, int base)
{
    // 创建一个栈
    Stack* stack = createStack(100);
    // 将num除以base的余数依次压入栈中
    while (num)
    {
        push(stack, num % base);
        num /= base;
    }
    // 依次从栈中弹出元素
    while (!isEmpty(stack))
    {
        int remainder = pop(stack);
        if (remainder < 10)
        {
            printf("%d", remainder);
        }
        else
        {
            printf("%c", 'A' + remainder - 10);
        }
    }
    printf("\n");
}

int main()
{
    int X, M;
    scanf("%d %d", &X, &M);
    ConvertToBase(X, M);
    return 0;
}
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

// 递归版本的进制转换函数
void ConvertToBaseRecursive(int num, int base)
{
    // 如果num不为0，继续递归
    if(num)
    {
        ConvertToBaseRecursive(num / base, base);
        int remainder = num % base;
        // 如果余数小于10，直接打印余数
        if(remainder < 10)
        {
            printf("%d", remainder);
        }
        // 如果余数大于等于10，打印对应的字母
        else
        {
            printf("%c", 'A' + remainder - 10);
        }
    }
    else
    {
        return;
    }
}

// 字符串反转函数
void StringReverse(char* string)
{
    int length = (int)strlen(string);
    for (int i = 0; i < length / 2; i++)
    {
        char tmp = string[i];
        string[i] = string[length - i - 1];
        string[length - i - 1] = tmp;
    }
}

// 字符串版本的进制转换函数
char* ConvertToBase(int num, int base)
{
    char* ConvertedNum = (char*)calloc(101, sizeof(char));
    int i = 0, remainder;
    while (num)
    {
        remainder = num % base;
        // 如果余数小于10，将余数转换为字符并添加到字符串中
        if(remainder < 10)
        {
            ConvertedNum[i] = remainder + '0';
        }
        // 如果余数大于等于10，将余数转换为对应的字母并添加到字符串中
        else
        {
            ConvertedNum[i] = remainder + 'A' - 10;
        }
        num /= base;
        i++;
    }
    // 反转字符串
    StringReverse(ConvertedNum);
    return ConvertedNum;
}

int main()
{
    int num, base;
    scanf("%d %d", &num, &base);
    // 使用字符串版本的进制转换函数
    // char* ConvertedNum = ConvertToBase(num, base);
    // printf("%s\n", ConvertedNum);
    // free(ConvertedNum);
    // 使用递归版本的进制转换函数
    ConvertToBaseRecursive(num, base);
    printf("\n");
    return 0;
}
