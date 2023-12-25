/*
1839：【05NOIP提高组】谁拿了最多奖学金

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 26231     通过数: 12468
【题目描述】
某校的惯例是在每学期的期末考试之后发放奖学金。发放的奖学金共有五种，获取的条件各自不同：

1)院士奖学金，每人8000元，期末平均成绩高于80分（>80），并且在本学期内发表1篇或1篇以上论文的学生均可获得；

2)五四奖学金，每人4000元，期末平均成绩高于85分（>85），并且班级评议成绩高于80分（>80）的学生均可获得；

3)成绩优秀奖，每人2000元，期末平均成绩高于90分（>90）的学生均可获得；

4)西部奖学金，每人1000元，期末平均成绩高于85分（>85）的西部省份学生均可获得；

5)班级贡献奖，每人850元，班级评议成绩高于80分（>80）的学生干部均可获得；

只要符合条件就可以得奖，每项奖学金的获奖人数没有限制，每名学生也可以同时获得多项奖学金。例如姚林的期末平均成绩是87分，班级评议成绩82分，同时他还是一位学生干部，那么他可以同时获得五四奖学金和班级贡献奖，奖金总数是4850元。

现在给出若干学生的相关数据，请计算哪些同学获得的奖金总数最高（假设总有同学能满足获得奖学金的条件）。

【输入】
第一行是一个整数N（1 <= N <= 100），表示学生的总数。接下来的N行每行是一位学生的数据，从左向右依次是姓名，期末平均成绩，班级评议成绩，是否是学生干部，是否是西部省份学生，以及发表的论文数。姓名是由大小写英文字母组成的长度不超过20的字符串（不含空格）；期末平均成绩和班级评议成绩都是0到100之间的整数（包括0和100）；是否是学生干部和是否是西部省份学生分别用一个字符表示，Y表示是，N表示不是；发表的论文数是0到10的整数（包括0和10）。每两个相邻数据项之间用一个空格分隔。

【输出】
三行，第一行是获得最多奖金的学生的姓名，第二行是这名学生获得的奖金总数。如果有两位或两位以上的学生获得的奖金最多，输出他们之中在输入文件中出现最早的学生的姓名。第三行是这N个学生获得的奖学金的总数。

【输入样例】
4
YaoLin 87 82 Y N 0
ChenRuiyi 88 78 N Y 1
LiXin 92 88 N N 0
ZhangQin 83 87 Y N 1
【输出样例】
ChenRuiyi
9000
28700
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student
{
    char name[20];  // 学生姓名
    int score1;  // 学生的第一科成绩
    int score2;  // 学生的第二科成绩
    char west;  // 学生是否是西部学生
    char leader;  // 学生是否是班级干部
    int paper;  // 学生的论文数量
    int scholarship;  // 学生的奖学金总额
}Stu;

int main()
{
    int n, maxindex = 0, sum = 0;  // n是学生数量，maxindex是获得最多奖学金的学生的索引，sum是所有学生的奖学金总额
    scanf("%d", &n);  // 从标准输入读取学生数量
    Stu* stu = (Stu*)calloc(n, sizeof(Stu));  // 动态分配n个Stu类型的内存空间
    for (int i = 0; i < n; i++)  // 遍历每个学生
    {
        // 从标准输入读取学生的信息
        scanf("%s %d %d %c %c %d", stu[i].name, &stu[i].score1, &stu[i].score2, &stu[i].leader, &stu[i].west, &stu[i].paper);
        // 根据学生的信息计算奖学金总额
        if (stu[i].score1 > 80)
        {
            if (stu[i].paper >= 1)
            {
                stu[i].scholarship += 8000;
            }
            if (stu[i].score1 > 85)
            {
                if (stu[i].score2 > 80)
                {
                    stu[i].scholarship += 4000;
                }
                if (stu[i].west == 'Y')
                {
                    stu[i].scholarship += 1000;
                }
                if (stu[i].score1 > 90)
                {
                    stu[i].scholarship += 2000;
                }
            }
        }
        if (stu[i].score2 > 80 && stu[i].leader == 'Y')
        {
            stu[i].scholarship += 850;
        }
        // 更新获得最多奖学金的学生的索引
        if (stu[maxindex].scholarship < stu[i].scholarship)
        {
            maxindex = i;
        }
        // 更新所有学生的奖学金总额
        sum += stu[i].scholarship;
    }
    // 打印获得最多奖学金的学生的姓名和奖学金总额，以及所有学生的奖学金总额
    printf("%s\n%d\n%d\n", stu[maxindex].name, stu[maxindex].scholarship, sum);
    free(stu);  // 释放动态分配的内存空间
    return 0;  // 函数返回0，表示程序正常结束
}