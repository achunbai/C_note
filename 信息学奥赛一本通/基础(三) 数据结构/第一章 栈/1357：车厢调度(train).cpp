//
//  1357：车厢调度(train).cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/2/13.
//

/*
 1357：车厢调度(train)

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 24146     通过数: 12481
 【题目描述】
 有一个火车站，铁路如图所示，每辆火车从A驶入，再从B方向驶出，同时它的车厢可以重新组合。假设从A方向驶来的火车有n
 节（n≤1000
 ），分别按照顺序编号为1
 ，2
 ，3
 ，…，n
 。假定在进入车站前，每节车厢之间都不是连着的，并且它们可以自行移动到B处的铁轨上。另外假定车站C可以停放任意多节车厢。但是一旦进入车站C，它就不能再回到A方向的铁轨上了，并且一旦当它进入B方向的铁轨，它就不能再回到车站C。

 负责车厢调度的工作人员需要知道能否使它以a1
 ,a2
 ,…,an
 的顺序从B方向驶出，请来判断能否得到指定的车厢顺序。

 【输入】
 第一行为一个整数n
 ，其中n≤1000
 ，表示有n
 节车厢，第二行为n
 个数字，表示指定的车厢顺序。

 【输出】
 如果可以得到指定的车厢顺序，则输出一个字符串“YES”，否则输出“NO”（注意要大写，不包含引号）。

 【输入样例】
 5
 5 4 3 2 1
 【输出样例】
 YES
 【提示】
 解析：观察发现，整个调度过程其实是在模拟入栈出栈的过程，而这个过程中，我们可以分成三种状态：栈前、栈中、栈后。我们可以发现，当某个数字出栈了，说明比它小的数字要么已经出栈了，要么还在栈里，不能是入栈前状态，并且在栈中的顺序是从大到小的(从栈顶往栈底看)，比如出5，那么1，2，3，4要么已经在5之前出了，要么还在栈中（假如1，3，4在栈中，从栈顶往栈底看依次为4，3，1），不能是入栈前的状态。如果某个数字要出栈，那么当前在栈中的数字都必须小于它，否则就与栈的性质矛盾，不合法，于是我们可以这样解决：

 从第一个数字开始扫描，a[i]表示当前出栈的数字，如果有比a[i]大的数字还在栈中，那么就产生矛盾，输出“NO”；否则，标记当前数字a[i]为栈后状态，那么[1, a[i]-1]这些数字如果还没出栈，标记为栈中状态。具体我们可以用0表示为确定状态，1表示栈中状态，2表示栈后状态。
 */

// #include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

// 判断是否能以指定的顺序出栈，即能不能大的比小的先出来

int main(int argc, const char * argv[])
{
    int n, order = 1;
    cin >> n;
    stack<int> coach;
    for(int i = 1; i <= n; i++)
    {
        int coach_id;
        cin >> coach_id;
        // 如果车厢id比顺序id要少，那就入栈
        while (order <= coach_id)
        {
            coach.push(order++);
        }
        if(coach_id == coach.top())
            coach.pop();
        else
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
