/*
### 习题662 连接字符串

#### [问题描述]

连接两个字符串。

#### [输入描述]

输入两个字符串。

#### [输出描述]

输出拼接后的字符串。

#### [输入样例1]

```text
abcd
def
```

#### [输出样例1]

```text
abcddef
```

#### [输入样例2]

```text
abcdef
123
```

#### [输出样例2]

```text
abcdef123
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
	int length1 = strlen(str1), length2 = strlen(str2);	// 获取字符串长度
	for (int i = 0 ; i < length2; i++)	// 遍历str2
	{
		str1[i + length1] = str2[i];	// 将str2中的字符添加到str1后面
	}
	str1[length1 + length2] = '\0';	// 添加字符串结束符
	puts(str1);
	return 0;
}
```

```C
#include<stdio.h>
char* usr_strcat(char*str2, const char*str1) {
	//指针判空
	if (str1 == NULL || str2 == NULL) {
		return 0;
	}
	char* tmp = str2;
	while (*str2) {
		str2++;
	}
	while (*str1) {
		*str2++ = *str1++;
	}
	*str2 = '\0';
	return tmp;
	
}
int main() {
	char str1[100];
	char str2[100];
	gets(str1);
	gets(str2);
	char*p=m_strcat(str2, str1);
	printf("%s", p);
	return 0;
}

```
*/

#include <stdio.h>
#include <string.h>

// strcat函数的实现，strcat函数功能如下：
// 调用方法：int* str = usr_strcat(str1, str2);
// 将字符串str2连接到字符串str1的末尾
// 返回值为str1的首地址
int* usr_strcat(int* str1, const int* str2)
{
    // 指针判空 若为空则返回0
    if (str1 == NULL || str2 == NULL)
    {
        return 0;
    }
    // 保存str1的首地址至tmp
    int* tmp = str1;
    while (*str1)
    {
        str1++;
    }
    while (*str2)
    {
        // 将str2中的字符添加到str1后面
        *str1++ = *str2++;
    }
    *str1 = '\0';
    // 返回首地址，实现链式操作
    return tmp;
}

int main()
{
	char str1[100], str2[100];
	gets(str1);
	gets(str2);
	usr_strcat(str1, str2);
	puts(str1);
	return 0;
}