/*
1147：最高分数的学生姓名

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 33580     通过数: 24502
【题目描述】
输入学生的人数，然后再输入每位学生的分数和姓名，求获得最高分数的学生的姓名。

【输入】
第一行输入一个正整数N（N <= 100），表示学生人数。接着输入N行，每行格式如下：

       分数 姓名

分数是一个非负整数，且小于等于100；

姓名为一个连续的字符串，中间没有空格，长度不超过20。

数据保证最高分只有一位同学。

【输出】
获得最高分数同学的姓名。

【输入样例】
5
87 lilei
99 hanmeimei
97 lily
96 lucy
77 jim
【输出样例】
hanmeimei
*/
#include <stdio.h>
#include <stdlib.h>

// 定义学生结构体
typedef struct Student{
    char name[21];  // 学生姓名
    int score;  // 学生分数
}Stu;

int main()
{
    int n, maxp = 0;  // 学生数量和分数最高的学生的位置
    scanf("%d", &n);  // 读取学生数量

    // 创建学生数组
    Stu* stu = (Stu*)calloc(n, sizeof(Stu));

    // 读取每个学生的分数和姓名
    for (int i = 0; i < n; i++)
    {
        scanf("%d %s", &stu[i].score, stu[i].name);

        // 检查当前学生的分数是否是最高的
        if(stu[i].score > stu[maxp].score)
            maxp = i;
    }

    // 打印出分数最高的学生的姓名
    printf("%s\n", stu[maxp].name);

    // 释放学生数组
    free(stu);

    return 0;
}
