/*
1399：甲流病人初筛

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 37958     通过数: 23978
【题目描述】
目前正是甲流盛行时期，为了更好地进行分流治疗，医院在挂号时要求对病人的体温和咳嗽情况进行检查，对于体温超过37.5度（含等于37.5度）并且咳嗽的病人初步判定为甲流病人（初筛）。现需要统计某天前来挂号就诊的病人中有多少人被初筛为甲流病人。

【输入】
第一行是某天前来挂号就诊的病人数n。(n<200)

其后有n行，每行是病人的信息，包括三个信息：姓名（字符串，不含空格，最多8个字符）、体温（float）、是否咳嗽（整数，1表示咳嗽，0表示不咳嗽）。每行三个信息之间以一个空格分开。

【输出】
按输入顺序依次输出所有被筛选为甲流的病人的姓名，每个名字占一行。之后在输出一行，表示被筛选为甲流的病人数量。

【输入样例】
5
Zhang 38.3 0
Li 37.5 1
Wang 37.1 1
Zhao 39.0 1
Liu 38.2 1
【输出样例】
Li
Zhao
Liu
3
*/
#include <stdio.h>
#include <stdlib.h>

// 定义病人结构体
typedef struct Patient{
    char name[9];  // 姓名
    float temp;  // 体温
    int cough;  // 是否咳嗽，1表示咳嗽，0表示不咳嗽
    int flag;  // 是否被初筛为甲流病人，1表示是，0表示否
}Patient;

int main()
{
    int n, sum = 0;  // n是病人数量，sum是被初筛为甲流病人的数量
    scanf("%d", &n);  // 输入病人数量
    Patient* Pat = (Patient*)calloc(n, sizeof(Patient));  // 分配内存存储病人信息
    for (int i = 0; i < n; i++)
    {
        // 输入病人信息
        scanf("%s %f %d", Pat[i].name, &Pat[i].temp, &Pat[i].cough);
        // 判断是否被初筛为甲流病人
        if(Pat[i].temp >= 37.5 && Pat[i].cough == 1)
        {
            Pat[i].flag = 1;  // 标记为甲流病人
            sum++;  // 甲流病人数量加1
        }
        else
            Pat[i].flag = 0;  // 标记为非甲流病人
    }
    // 输出被初筛为甲流病人的姓名
    for (int i = 0; i < n; i++)
        if(Pat[i].flag == 1)
            printf("%s\n", Pat[i].name);
    // 输出被初筛为甲流病人的数量
    printf("%d\n", sum);
    // 释放内存
    free(Pat);
    return 0;
}
