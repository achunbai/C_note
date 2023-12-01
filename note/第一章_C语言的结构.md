# 第一章 C语言的结构

## 尖括号和圆括号的区别

```C
#include<stdio.h> // 从系统配置环境寻找 系统路径 -> 项目路径
#include"stdio.h" // 项目路径 -> 系统路径
```

## 编译器对注释的理解

当成空格

```C
int main()
{
	return/*加个注释*/0;
}
```

## C语言的标识符

- 数字、字母、下划线、$
- 不可以以数字开头
- 不与关键字重名
- 大小写敏感

## 常见类型格式符

```C
int main() //2个参数 1.传入参数的个数 2.传入的参数
{
	printf("Halo\n");//f: format 格式化输出
	int a = 99;	//%d	4b,32bit	1符号，31数值	表示范围 -2^31-2^31-1
	float b;	//%f
	double c;	//%lf
	char d;		//%c
	return 0;
}
```

## main函数的两个参数

```C
int main(int argc,char *argv[])
```

```C
int main(int argc,char **argv)
```

其参数argc和argv用于运行时，把命令行参数传入主程。其中ARG是指arguments，即参数。具体含义如下:
1. int argc：arguments count(参数计数)
    - count of cmd line args,运行程序传送给main函数的命令行参数总个数,包括可执行程序名,其中当argc=1时表示只有一个程序名称,此时存储在argv[0]中.
2. char **argv：arguments value/vector(参数值)
    - pointer to table of cmd line args,字符串数组,用来存放指向字符串参数的指针数组,每个元素指向一个参数,空格分隔参数,其长度为argc.数组下标从0开始,argv[argc]=NULL.
    - argv[0]
      - 指向程序运行时的全路径名
    - argv[1]
      - 指向程序在DOS命令中执行程序名后的第一个字符串
    - argv[2]
      - 指向执行程序名后的第二个字符串
    - argv[argc]
      - 为NULL.

## C语言中的关键字，不可作为变量声明

| 关键字 | 解释 |
| :----: | :---- |
| auto | 声明自动变量 |
| break | 用于跳出当前循环 |
| case | 开关语句中的分支标记 |
| char | 声明字符型变量或函数 |
| const | 声明只读变量 |
| continue | 结束当前循环，开始下一轮循环 |
| default | 开关语句中的“其他”分支 |
| do | 其后紧跟循环体 |
| double | 声明双精度变量或函数 |
| else | 条件语句否定分支 |
| enum | 声明枚举类型 |
| extern | 声明变量是在其他文件定义 |
| float | 声明浮点型变量或函数 |
| for | 遍历循环 |
| goto | 无条件跳转语句 |
| if | 条件语句 |
| inline | 内联函数 |
| int | 声明整型变量或函数 |
| long | 声明长整型变量或函数 |
| register | 声明寄存器变量 |
| restrict | 限制指针 |
| return | 函数返回语句 |
| short | 声明短整型变量或函数 |
| signed | 声明有符号类型变量 |
| sizeof | 得到特定类型或特定类型变量的大小 |
| static | 声明静态变量 |
| struct | 声明结构体变量或函数 |
| switch | 用于多条件判断语句 |
| typedef | 用以给数据类型取别名 |
| union | 声明共用数据类型 |
| unsigned | 声明无符号类型变量 |
| void | 声明函数无返回值或无参数，声明无类型指针 |
| volatile | 指定变量的值有可能会被系统或其他进程/线程改变 |
| while | 条件循环或死循环 |
| _Bool | 布尔类型 |
| _Complex | 复数类型 |
| _Imaginary | 虚数类型 |

## C语言中各种进制数的表达

| 进制 | 描述 | 示例 |
| :----: | :---- | :---- |
| 二进制 | 由0和1两个数字组成，使用时必须以`0b`或`0B`（不区分大小写）开头 | `int a = 0b101;` |
| 八进制 | 由0~7八个数字组成，使用时必须以0开头（注意是数字0，不是字母o） | `int a = 015;` |
| 十进制 | 由0~9十个数字组成，没有任何前缀，和我们平时的书写格式一样 | `int a = 163;` |
| 十六进制 | 由数字 0 ~ 9 、字母 A ~ F 或 a ~ f（不区分大小写）组成，使用时必须以`0x`或`0X`（不区分大小写）开头 | `int a = 0X2A;` |

## scanf函数补充

scanf有返回值，返回输入参数的个数

可以用%nd来控制输入n位整数，其他类型亦然

可以用%*nd来跳过输入n位整数，其他类型亦然

## 习题

### 习题001 输出 "Hello, World!"

#### [问题描述]

在屏幕上输出 "Hello, World!"。

#### [输入描述]

无

#### [输出描述]

输出 "Hello, World!"

#### [输入样例1]

无

#### [输出样例1]

```text
Hello, World!
```

#### 代码实现

```C
#include<stdio.h> 

int main() 
{
	printf("Hello, World!");
	return 0;
}
```

### 习题002 输出整数

#### [问题描述]

输出一个整数。

#### [输入描述]

输入一个整数。

#### [输出描述]

输出一个整数。

#### [输入样例1]

```text
45
```

#### [输出样例1]

```text
45
```

#### 代码实现

```C
#include<stdio.h>
int main()
{
	int a;
	scanf("%d", &a);
	printf("%d", a);
	return 0;
}
```
