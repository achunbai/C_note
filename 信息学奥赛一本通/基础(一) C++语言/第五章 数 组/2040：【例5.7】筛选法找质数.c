/*
2040：【例5.7】筛选法找质数

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 32967     通过数: 22607
【题目描述】
用筛法求出n(2≤n≤1000)
以内的全部质数。

【输入】
输入n
。

【输出】
多行，由小到大的质数。

【输入样例】
10
【输出样例】
2
3
5
7
*/
// 试除法
// 每个数都从2到sqrt(n)试除，若能整除，则不是质数

// 厄拉多塞筛选法
// 从2开始，将2的倍数全部筛掉，然后再从3开始，将3的倍数全部筛掉，以此类推
// 时间复杂度为O(nloglogn)
#include <stdio.h>

int main()
{
	int n, prime[1001] = { 1,1 };
	scanf("%d", &n);
	for (int i = 2; i < 1001; i++)
	{
		if (!prime[i])
		{
			for (int j = i + i; j < 1001; j += i)
			{
				prime[j] = 1;
			}
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (!prime[i])
		{
			printf("%d\n", i);
		}
	}
	return 0;
}

/*
课上示例C++代码：
#include<iostream>
using namespace std;
//埃氏筛法求素数：把素数的倍数筛掉
const int N = 1e3 + 10;
bool vis[N];//vis[i]=1代表数字i是素数，vis[i]=0代表数字i不是素数
int primes[N];//素数表-所有的素数
int n, id = 0;
//时间复杂度-O（nloglogn）
void E_sieve() {
	fill(vis+2,vis+n+1,1);
	for (int i = 2; i <= n; i++) {
		if (vis[i]) {//如果i是素数
			primes[id++] = i;//存进素数表
			//把i的倍数(合数)筛掉
			for (int j = i * i; j <= n; j+=i) {
				vis[j] = 0;
			}
		}
	}
}
int main() {
	cin >> n;
	E_sieve();
	for (int i = 0; i < id ; i++) cout << primes[i] << endl;
	return 0;
}


//#include<iostream>
//using namespace std;
////判定x是否是素数（除了1和本身之外没有其余因子）
//bool isprime(int x) {
//	if (x < 2) return false;
//	for (int i = 2; i*i <= x; i++) 
//		if (x % i == 0) return false;//代表不是素数
//	return true;//代表是素数
//}
//int main() {
//	int n;  cin >> n;
//	for (int i = 2; i <= n; i++) {
//		if (isprime(i)) cout << i << endl;
//	}
//	return 0;
//}
*/