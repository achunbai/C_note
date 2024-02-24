//
//  1178：成绩排序.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/20.
//

/*
 1178：成绩排序

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 71886     通过数: 30059
 【题目描述】
 给出班里某门课程的成绩单，请你按成绩从高到低对成绩单排序输出，如果有相同分数则名字字典序小的在前。

 【输入】
 第一行为n (0 < n < 20)，表示班里的学生数目；

 接下来的n行，每行为每个学生的名字和他的成绩, 中间用单个空格隔开。名字只包含字母且长度不超过20，成绩为一个不大于100的非负整数。

 【输出】
 把成绩单按分数从高到低的顺序进行排序并输出，每行包含名字和分数两项，之间有一个空格。

 【输入样例】
 4
 Kitty 80
 Hanmeimei 90
 Joey 92
 Tim 28
 【输出样例】
 Joey 92
 Hanmeimei 90
 Kitty 80
 Tim 28
 */
#include <bits/stdc++.h>

using namespace std;

const int N = 50;

typedef struct Student
{
    string name;
    int score;
}Stu;

Stu s[N];

bool cmp(Stu a, Stu b)
{
    if(a.score != b.score)
        return a.score > b.score;
    else
        return a.name < b.name;
}

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> s[i].name >> s[i].score;
    }
    sort(s, s + n, cmp);
    for(int i = 0; i < n; i++)
    {
        cout << s[i].name << " " << s[i].score << endl;
    }
    return 0;
}
