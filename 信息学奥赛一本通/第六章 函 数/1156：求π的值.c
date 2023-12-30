/*
1156：求π的值

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 57510     通过数: 20965
【题目描述】
根据公式：

arctanx(x)=x−x33+x55−x77+...
和π=6arctanx(13√)
定义函数 arctanx(x)
，求当最后一项小于10−6
时π
的值。

【输入】
（无）

【输出】
π
的值。保留到小数点后10
位。

【输入样例】
（无）
【输出样例】
（无）
*/

/*
#include <stdio.h>
#include <math.h>

long double GetPi(long double acc)
{
    long double x = 1 / sqrt(3), pi = 0, current = x;
    int i, j;
    long double pow_neg_one = 1;
    for (i = 1, j = 0; current > acc; i+=2, j++)
    {
        current = pow(x, i) / i;
        pi += pow_neg_one * 6 * current;
        pow_neg_one *= -1;
    }
    current = pow(x, i) / i;
    pi += pow_neg_one * 6 * current;
    return pi;
}

int main()
{
    printf("%.10Lf", GetPi(10e-6));
    return 0;
}
*/

#include <stdio.h>
#include <math.h>

// 定义一个函数，用于计算π的值
long double GetPi(long double acc)
{
    // 初始化x的值为1/根号3
    long double x = 1 / sqrt(3), pi = 0, current = x;
    int i, j;
    // 当current的值大于acc时，继续迭代
    for (i = 1, j = 0; current > acc; i+=2, j++)
    {
        // 计算current的值
        current = pow(x, i) / i;
        // 更新pi的值
        pi += pow(-1, j) * 6 * current;
    }
    // 计算最后一次迭代的值
    current = pow(x, i) / i;
    // 更新pi的值
    pi += pow(-1, j) * 6 * current;
    // 返回pi的值
    return pi;
}

int main()
{
    // 打印出π的值，保留10位小数
    printf("%.10Lf", GetPi(10e-6));
    return 0;
}
