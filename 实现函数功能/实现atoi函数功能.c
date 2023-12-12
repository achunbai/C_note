/*
### 习题668 实现atoi函数的功能

#### [问题描述]

atoi函数，主要功能是将一个字符串转变为整数，例如将“12345”–>12345

#### [输入描述]

输入一个字符串。

#### [输出描述]

输出转换成整型后的值

异常字符返回0

#### [输入样例1]

```text
42344
```

#### [输出样例1]

```text
42344
```

#### [输入样例2]

```text
-12345
```

#### [输出样例2]

```text
-12345
```

#### [输入样例3]

```text
agsa
```

#### [输出样例3]

```text
0
```

#### 代码实现

```C
#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	char str[100];
	gets(str);
	int flag = 0;
	long long num = 0;	// 用long long类型存储数字，防止溢出
	for (int i = 0 ; i < strlen(str); i++)
	{
		if (i == 0 && str[i] == '-')		// 如果第一位是负号，标志置1
		{
			flag = 1;
		}
		else if (str[i] >= '0' && str[i] <= '9')		// 如果为数字，则计算数字大小，字大小为每一位数字乘以10的n次方，n为该数字位数-1
		{
			num += (str[i] - '0') * pow(10, strlen(str) - i - 1);
		}
		else
		{
			printf("0");		// 如果不是数字，则输出0，程序终止
			return 0;
		}
	}
	if (flag)
	{
		num = 0 - num;	// 如果第一位是负号，将数字取反
	}
	printf("%lld", num);
	return 0;
}
```
*/

#include <stdio.h>
#include <string.h>

// atoi函数的功能如下：
// 调用方法：int num = usr_atoi(str);
// 1. 忽略前面的空格字符；
// 2. 直到遇到数字或正负符号才开始做转换；
// 3. 遇到非数字或字符串结束时('\0')才结束转换，并将结果返回；
// 4. 如果不能转换成int或者str为空指针，则返回0。

// 这个版本将空格忽略，如果输入的数据中含有空格，则直接跳过空格，记为一个数
long long usr_atoi(const char* str)
{
    if (str == NULL)
    {
        return 0;
    }
    int flag = 0;
    long long num = 0;	// 用long long类型存储数字，防止溢出
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (i == 0 && str[i] == '-')    // 如果第一位是负号，标志置1
        {
            flag = 1;
        }
        else if ((i == 0 && str[i] == '+') || str[i] == ' ')   // 如果第一位是正号，标志不变，继续循环，且若为空格，则直接跳过本次循环，即直接进行i++
        {
            continue;
        }
        else if (str[i] >= '0' && str[i] <= '9')    // 如果为数字，则计算数字大小，字大小为每一位数字乘以10的n次方，n为该数字位数-1
        {
            num = num * 10 + str[i] - '0';
        }
        else
        {
            return 0;   // 如果不是数字，则返回0，程序终止
        }
    }
    if (flag)
    {
        num = num * -1;	// 如果第一位是负号，将数字取反
    }
    return num;
}

int main()
{
    char str[100];
    gets(str);
    printf("%lld", usr_atoi(str));
    return 0;
}