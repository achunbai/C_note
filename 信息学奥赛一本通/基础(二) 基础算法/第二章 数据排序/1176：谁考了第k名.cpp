//
//  1176：谁考了第k名.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/19.
//

/*
 1176：谁考了第k名

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 78402     通过数: 35541
 【题目描述】
 在一次考试中，每个学生的成绩都不相同，现知道了每个学生的学号和成绩，求考第k名学生的学号和成绩。

 【输入】
 第一行有两个整数，分别是学生的人数n（1≤n≤100）
 ，和求第k名学生的k（1≤k≤n）
 。

 其后有n
 行数据，每行包括一个学号（整数）和一个成绩（浮点数），中间用一个空格分隔。

 【输出】
 输出第k
 名学生的学号和成绩，中间用空格分隔。（注：请用%g
 输出成绩）

 【输入样例】
 5 3
 90788001 67.8
 90788002 90.3
 90788003 61
 90788004 68.4
 90788005 73.9
 【输出样例】
 90788004 68.4
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 10;

typedef struct Studetn
{
    int id;
    double score;
}Stu;

Stu stu[N];

bool cmp(Stu a, Stu b)
{
    return a.score > b.score;
}

int main(int argc, const char * argv[])
{
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> stu[i].id >> stu[i].score;
    }
    sort(stu, stu + n, cmp);
    cout << stu[k - 1].id << " " << stu[k - 1].score << endl;
    return 0;
}
