/*
 1332：【例2-1】周末舞会

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 27315     通过数: 19721
 【题目描述】
 假设在周末舞会上，男士们和女士们进入舞厅时，各自排成一队。跳舞开始时，依次从男队和女队的队头上各出一人配成舞伴。规定每个舞曲能有一对跳舞者。若两队初始人数不相同，则较长的那一队中未配对者等待下一轮舞曲。现要求写一个程序，模拟上述舞伴配对问题。

 【输入】
 第一行两队的人数;

 第二行舞曲的数目。

 【输出】
 配对情况。

 【输入样例】
 4 6
 7
 【输出样例】
 1 1
 2 2
 3 3
 4 4
 1 5
 2 6
 3 1
 */
#include <iostream>
#include <queue>
using namespace std;

int main(int argc, const char * argv[])
{
    int nq1, nq2, song;
    cin >> nq1 >> nq2 >> song;
    queue<int>q1, q2;
    for(int i = 1; i <= nq1; i++)
    {
        q1.push(i);
    }
    for(int i = 1; i <= nq2; i++)
    {
        q2.push(i);
    }
    for(int i = 1; i <= song; i++)
    {
        q1.push(q1.front());
        q2.push(q2.front());
        cout << q1.front() << " " << q2.front() << endl;
        q1.pop();
        q2.pop();
    }
    return 0;
}
