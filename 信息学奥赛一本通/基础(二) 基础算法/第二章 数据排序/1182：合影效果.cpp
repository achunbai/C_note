//
//  1182：合影效果.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/20.
//

/*
 1182：合影效果

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 32394     通过数: 18717
 【题目描述】
 小云和朋友们去爬香山，为美丽的景色所陶醉，想合影留念。如果他们站成一排，男生全部在左（从拍照者的角度），并按照从矮到高的顺序从左到右排，女生全部在右，并按照从高到矮的顺序从左到右排，请问他们合影的效果是什么样的（所有人的身高都不同）？

 【输入】
 第一行是人数n
 （2≤n≤40
 ，且至少有1
 个男生和1
 个女生）。

 后面紧跟n
 行，每行输入一个人的性别（男male或女female）和身高（浮点数，单位米），两个数据之间以空格分隔。

 【输出】
 n
 个浮点数，模拟站好队后，拍照者眼中从左到右每个人的身高。每个浮点数需保留到小数点后2
 位，相邻两个数之间用单个空格隔开。

 【输入样例】
 6
 male 1.72
 male 1.78
 female 1.61
 male 1.65
 female 1.70
 female 1.56
 【输出样例】
 1.65 1.72 1.78 1.70 1.61 1.56
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 50;

typedef struct Person
{
    bool gender;
    double height;
}P;

P p[N];

bool cmp(P a, P b)
{
    if(a.gender != b.gender)
        return a.gender > b.gender;
    else if(a.gender && b.gender)
        return a.height < b.height;
    else
        return a.height > b.height;
}

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string gender;
        cin >> gender >> p[i].height;
        if(gender == "male")
            p[i].gender = 1;
    }
    sort(p, p + n, cmp);
    for(int i = 0; i < n; i++)
    {
        cout << fixed << setprecision(2) << p[i].height << " ";
    }
    cout << endl;
    return 0;
}
