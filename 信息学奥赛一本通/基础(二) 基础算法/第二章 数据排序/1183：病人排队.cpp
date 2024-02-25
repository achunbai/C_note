//
//  1183：病人排队.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/19.
//

/*
 1183：病人排队

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 44410     通过数: 19491
 【题目描述】
 病人登记看病，编写一个程序，将登记的病人按照以下原则排出看病的先后顺序：

 1.老年人（年龄 ≥60
 岁）比非老年人优先看病。

 2.老年人按年龄从大到小的顺序看病，年龄相同的按登记的先后顺序排序。

 3.非老年人按登记的先后顺序看病。

 【输入】
 第1行，输入一个小于100
 的正整数，表示病人的个数；

 后面按照病人登记的先后顺序，每行输入一个病人的信息，包括：一个长度小于10
 的字符串表示病人的ID（每个病人的ID各不相同且只含数字和字母），一个整数表示病人的年龄，中间用单个空格隔开。

 【输出】
 按排好的看病顺序输出病人的ID，每行一个。

 【输入样例】
 5
 021075 40
 004003 15
 010158 67
 021033 75
 102012 30
 【输出样例】
 021033
 010158
 021075
 004003
 102012
 */
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct Patient
{
    string id;
    int age, order;
}P[110];

bool cmp(Patient a, Patient b)
{
    if((a.age >= 60 || b.age >= 60) && a.age != b.age)
        return a.age > b.age;
    else
        return a.order < b.order;
}

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> P[i].id >> P[i].age;
        P[i].order = i;
    }
    sort(P, P + n, cmp);
    for(int i = 0; i < n; i++)
    {
        cout << P[i].id << endl;
    }
    return 0;
}
