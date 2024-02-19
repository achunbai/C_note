//
//  1334：【例2-3】围圈报数.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/15.
//

/*
 1334：【例2-3】围圈报数

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 22035     通过数: 15128
 【题目描述】
 有ｎ
 个人依次围成一圈，从第１
 个人开始报数，数到第ｍ
 个人出列，然后从出列的下一个人开始报数，数到第ｍ
 个人又出列，…，如此反复到所有的人全部出列为止。设ｎ
 个人的编号分别为1，2，…，n
 ，打印出列的顺序。

 【输入】
 n
 和m
 。

 【输出】
 出列的顺序。

 【输入样例】
 4 17
 【输出样例】
 1 3 4 2
 【提示】
 n≤100
 。
 */

#include <iostream>
#include <queue>
using namespace std;

int main(int argc, const char * argv[])
{
    int n, pos;
    cin >> n >> pos;
    queue<int> q1;
    for(int i = 1; i <= n; i++)
    {
        q1.push(i);
    }
    while (!q1.empty())
    {
        for(int i = 1; i <= pos; i++)
        {
            if (i != pos)
            {
                q1.push(q1.front());
                q1.pop();
            }
            else
            {
                cout << q1.front() << " ";
                q1.pop();
            }
        }
    }
    return 0;
}
