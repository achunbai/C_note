/*
### 习题659 比较字符串是否相同

#### [问题描述]

比较字符串是否相同。

#### [输入描述]

输入两个字符串。

#### [输出描述]

当字符串完全相同时输出0。不完全相同时，比较对应位置不同字符的ASCII值，前者大于后者输出1反之输出-1。

#### [输入样例1]

```text
abced
abced
```

#### [输出样例1]

```text
0
```

#### [输入样例2]

```text
adfhn
add
```

#### [输出样例2]

```text
1
```

#### [输入样例3]

```text
aacdde
abc
```

#### [输出样例3]

```text
-1
```

#### 代码实现

```C
#include <stdio.h>
#include <string.h>

int main()
{
	char str1[100], str2[100];
	gets(str1);
	gets(str2);
	int length1 = strlen(str1), length2 = strlen(str2);
	for (int i = 0; i < (length1 > length2 ? length1 : length2); i++)	// 以较长的字符串为准
	{
		if (str1[i] > str2[i])	// 逐个字符比较，若不同则判断后输出，终止运行函数
		{
			printf("1");
			return 0;
		}
		else if (str1[i] < str2[i])
		{
			printf("-1");
			return 0;
		}
	}
	printf("0");	// 若两字符串完全相同，则输出0
	return 0;
}
```

```C
#include <stdio.h>

int usr_strcmp(const char* str1, const char* str2)
{
	if (str1 == NULL || str2 == NULL)
	{
		return 2;
	}
	while (*str1 == *str2)
	{
		if (*str1 == 0)
		{
			return 0;
		}
		str1++;
		str2++;
	}
	return (*str1 > *str2) ? 1 : -1;
}

int main()
{
	char str1[100], str2[100];
	gets(str1);
	gets(str2);
	printf("%d", usr_strcmp(str1, str2));
	return 0;
}
```
*/

#include <stdio.h>

// 与上面注释不同，以下函数完全实现strcmp函数功能
// strcmp函数功能如下：
// 调用方法：int result = strcmp(str1, str2);
// 1.若str1 > str2，返回正数，值为str1与str2第一个不同字符的ASCII码差值
// 2.若str1 < str2，返回负数，值为str1与str2第一个不同字符的ASCII码差值
// 3.若str1 = str2，返回0
int usr_strcmp(const char* str1, const char* str2)
{
	if (str1 == NULL || str2 == NULL)
	{
		return 2;
	}
	while (*str1 == *str2)
	{
		if (*str1 == 0)
		{
			return 0;
		}
		str1++;
		str2++;
	}
	return (*str1 > *str2) ? (*str1 - *str2) : (*str2 - *str1);
}

int main()
{
	char str1[100], str2[100];
	gets(str1);
	gets(str2);
	printf("%d", usr_strcmp(str1, str2));
	return 0;
}