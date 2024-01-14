/*
1082：求小数的某一位

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 80574     通过数: 40364
【题目描述】
分数ab
化为小数后，小数点后第n
位的数字是多少？

【输入】
三个正整数a，b，n
，相邻两个数之间用单个空格隔开。0<a<b<100，1<=n<=10000
。

【输出】
一个数字。

【输入样例】
1 2 1
【输出样例】
5
*/

// 代码1.0 只能通过一个，因为double在6位后会出现误差
// 并且输入数字很大的话，会出现溢出
/*
#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, n, result;
	scanf("%d %d %d", &a, &b, &n);
	result = pow(10, n) * a / b;
	result %= 10;
	printf("%d", result);
	return 0;
}
*/

// 代码2.0 通过全部
// float精度为小数点后6-7位
// double精度为小数点后15-16位
// 上面的版本因为小数点后精度不够，所以会出现误差
// 本题本质为数据类型的缺陷，需要使用数学思维进行思考
// 本题的思路是：利用同余定理，求a/b的小数部分
// 先求a/b的余数，再将余数乘以10，作为下一次循环的被除数
// 这样可以将a/b的小数部分一位一位求出来
// 最后循环n次后，a/b的小数部分就是a/b的商
#include <stdio.h>

int main()
{
	int a, b, n, result;
	scanf("%d %d %d", &a, &b, &n);
    // 运用除法法则求余数
	for (int i = 0; i < n; i++) // 循环n次，求a/b的小数部分
	{
		a %= b;   // 求a/b的余数，即a/b的小数部分
        a *= 10;    // 将余数a乘以10，作为下一次循环的被除数
	}
	result = a / b; // 循环n次后，a/b的小数部分就是a/b的商
	printf("%d", result);
	return 0;
}

/*
课上C++示例代码
#include<iostream>
#include<cmath>
using namespace std;

int main() {
	

	int a, b;  cin >> a >> b;
	int n; cin >> n;

	for (int i = 1; i <= n; i++) {
		a %= b;
		a *= 10;
	}
	cout << a / b << endl;
	//float   精度6-7位
	//double  精度15-16位   
	//double a, b;  cin >> a >> b;
	//int n; cin >> n;
	//cout << int(a / b * pow(10, n)) % 10 << endl;
	return 0;
}
*/