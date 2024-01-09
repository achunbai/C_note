/*
2039：【例5.6】冒泡排序

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 58868     通过数: 32326
【题目描述】
编程输入n(1≤n≤20)
个小于1000
非负整数，然后自动按从大到小的顺序输出。（冒泡排序）

【输入】
第一行，数的个数n
;

第二行，n
个非负整数。

【输出】
由大到小的n
个非负整数，每个数占一行。

【输入样例】
5
2 5 8 6 12
【输出样例】
12
8
6
5
2
*/

/*
冒泡排序是一种简单的排序算法，它重复地遍历待排序的列表，比较每对相邻的项，并在必要时交换它们。这个过程会一直重复，直到没有更多的项需要交换，也就是说，列表已经排序好了。

例如从序列中的第一个元素开始，依次对相邻的两个元素进行比较，如果前一个元素大于后一个元素则交换它们的位置。如果前一个元素小于或等于后一个元素，则不交换它们；这一比较和交换的操作一直持续到最后一个还未排好序的元素为止。

当这样的一趟操作完成时，序列中最大的未排序元素就被放置到了所有未排序的元素中最后的位置上，它就像水中的石块一样沉到了水底。而其它较小的元素则被移动到了序列的前面，就像水中的气泡冒到了水面一样。这就是为什么该算法被叫做冒泡排序的原因。
*/

// STL-标准模板库
// #include <algorithm>
// STL中所有传参为区间的形式的函数，都杨总遵守前闭后开的原则
// 1. 容器 vector list stack queue priority_queue set map unordered_set unordered_map
// 2. 迭代器 容器和算法之间的粘合剂
// 3. 算法 sort next_permutation lower_bound upper_bound
// 回调函数充当排序规则
// 回调函数示例
// bool cmp(int a, int b)
// {
// 	return a > b;
// }

// sort函数
// #include <algorithm>
// sort(begin, end, cmp)
// sort函数的底层实现是快速排序，时间复杂度为O(n*logn)
// 参数1：待排序区间的首元素的地址
// 参数2：待排序区间的尾元素的下一个地址
// 参数3：比较器，可以不写，默认从小到大排序（针对C++已有数据进行升序排序）
// 若此时是自定义数据类型或者需要改写的排序规则，则需要写cmp函数

// 冒泡排序基本原理：
// 比较相邻的元素。若按照从小到大排序，如果前一个比后一个大，就把大的往后放。
// 如此循环，每趟都可以保证最后一个数是最大的数。
// 每趟只需要比较总数-趟数次，因为每趟都会把最大的数放到最后，所以每趟都可以少比较一次。
// 数组尽量放在全局，否则会出现栈溢出的情况，并且全局区默认初始化为0，局部区默认初始化为随机值。

// 学排序需要学思想，只是排序直接用库函数sort就好了

#include <stdio.h>

int main()
{
	int num[20], n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}
	for (int i = 0; i < n - 1; i++) // 对于n个数来说，需要交换n-1趟
	{
		for (int j = 0; j < n - i - 1; j++) // 每趟需要交换n-i-1次（逐趟减少）
		{
			if (num[j+1] > num[j])  // 对较大值逐个交换到前面，保证每趟下来最前面的是最大值
			{
				int tmp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", num[i]);
	}
	return 0;
}

/*
课上C++示例代码：
#include<iostream>
#include<algorithm>//sort()
using namespace std;
const int N = 1e8 + 10;
int a[N];//默认初始化为0
//STL-标准模板库
//1.容器   vector  list  stack  queue  priority_queue  set  map  unordered_set   unordered_map
//2.迭代器 容器和算法之间的粘合剂
//3.算法   max_element()  min_element()  sort()
//回调函数充当排序规则
bool cmp(int left,int right) {
	return left > right;
}
int main() {

	int n;  cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	//数组名a是数组中首元素的地址,a+1*sizeof(type)就是a[1]地址，a+2就是a[2]地址，a+n是尾元素下一位地址
	//cout << &a[0] << endl << a << endl;
	//参数1：待排序区间的首元素的地址
	//参数2：待排序区间的尾元素的下一位的地址
	//参数3：比较器/比较规则，默认缺省，则针对C++已有数据类型进行升序排序
	//若此时是自定义数据类型或者需要改写排序规则，则必须重写参3
	sort(a,a+n,cmp);//STL中所有传参为区间的形式的函数，这个区间都要遵循前闭后开原则
	//sort()-底层是快排-时间复杂度O（nlogn）
	for (int i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
	return 0;
}
*/