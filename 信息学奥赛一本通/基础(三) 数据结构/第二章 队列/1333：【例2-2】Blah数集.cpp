//
//  1333：【例2-2】Blah数集.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/15.
//

/*
 1333：【例2-2】Blah数集

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 21909     通过数: 11790
 【题目描述】
 大数学家高斯小时候偶然间发现一种有趣的自然数集合Blah，对于以a为基的集合Ba定义如下：

 (1)a是集合Ba的基，且a是Ba的第一个元素；

 (2)如果x在集合Ba中，则2x+1和3x+1也都在集合Ba中；

 (3)没有其他元素在集合Ba中了。

 现在小高斯想知道如果将集合Ba中元素按照升序排列，第N个元素会是多少？

 【输入】
 输入包括很多行，每行输入包括两个数字，集合的基a(1≤a≤50))以及所求元素序号n(1≤n≤1000000)。

 【输出】
 对于每个输入，输出集合Ba的第n个元素值。

 【输入样例】
 1 100
 28 5437
 【输出样例】
 418
 900585
 */

#include <iostream>
#include <queue>
using namespace std;

int main(int argc, const char * argv[])
{
    int pos, result;
    while ( cin >> result >> pos) {
        queue<int> doubleP1, tripleP1;
        for(int i = 2; i <= pos; i++)
        {
            doubleP1.push(result * 2 + 1);
            tripleP1.push(result * 3 + 1);
            if (doubleP1.front() < tripleP1.front())
            {
                result = doubleP1.front();
                doubleP1.pop();
            }
            else if(doubleP1.front() > tripleP1.front())
            {
                result = tripleP1.front();
                tripleP1.pop();
            }
            else
            {
                result = doubleP1.front();
                doubleP1.pop();
                tripleP1.pop();
            }
        }
        cout << result << endl;
    }
    return 0;
}
