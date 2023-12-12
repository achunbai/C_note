/*
### 习题661 字符串复制

#### [问题描述]

将一个变量的字符串复制到另外一个变量中。

#### [输入描述]

输入一个字符串。

#### [输出描述]

输出拷贝之后的字符串。

#### [输入样例1]

```text
aafdkjnkl
```

#### [输出样例1]

```text
aafdkjnkl
```

#### [输入样例2]

```text
e435454
```

#### [输出样例2]

```text
e435454
```

#### 代码实现

```C
#include <stdio.h>
#include <string.h>

int main()
{
	char str1[100], str2[100];
	gets(str1);
	int i = 0;
	for ( ; i < strlen(str1); i++)	// 遍历字符串1，将其复制到字符串2
	{
		str2[i] = str1[i];
	}
	str2[i] = '\0';	// 字符串2最后加上结束符
	puts(str2);
	return 0;
}
```

```C
#include <stdio.h>
#include <string.h>

char* usr_strcpy(char* str2, const char* str1)
{
	// 指针判空
	if (str1 == NULL || str2 == NULL)
	{
		return 0; // 空指针相当于指向地址为0的指针
	}
	char* tmp = str2;
	while (*str1)
	{
		*str2++ = *str1++;
		// 等价于 *str1 = *str2; str1++; str2++;
	}
	*str2 = '\0';
	return tmp;	// 链式操作
}

int main()
{
	char str1[100], str2[100] = ""; // str2全部初始化为'\0'
	gets(str1);
	usr_strcpy(str2, str1);
	printf("%s", str2);
	return 0;
}
```
*/

#include <stdio.h>
#include <string.h>

// strcpy函数的实现，strcpy函数功能如下：
// 调用方法：char* str2 = strcpy(str2, str1);
// 将str1中的字符串复制到str2中
// 返回值为str2的首地址
char* usr_strcpy(char* str2, const char* str1)
{
	// 指针判空
	if (str1 == NULL || str2 == NULL)
	{
		return 0; // 空指针相当于指向地址为0的指针
	}
	char* tmp = str2;
	while (*str1)
	{
		// 将str1中的字符复制到str2中
        *str2++ = *str1++;
		// 等价于 *str1 = *str2; str1++; str2++;
	}
	*str2 = '\0';
	return tmp;	// 链式操作
}

int main()
{
	// str2全部初始化为'\0'，也可以避免str2中出现垃圾值
    char str1[100], str2[100] = ""; 
	gets(str1);
	usr_strcpy(str2, str1);
	printf("%s", str2);
	return 0;
}