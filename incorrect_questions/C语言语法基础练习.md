# C语言语法基础练习

#### 有以下程序，运行后输出的结果是：<font color=red>666</font>

```c
#include<stdio.h>

int main()
{
	int a = 666, b = 888;
	printf("%d\n", a, b);
	return 0;
}
```

参数入栈顺序为从右往左"%d\n"最后入栈，表示只输出一个值，即`a`

```c
#include<stdio.h>

int main()
{
	int a = 666, b = 888;
	printf("%d %d\n", a, b);
	return 0;
}
```

#### 有如下程序，程序运行后输出的结果是：<font color=red>59</font>

```C
#include<stdio.h>

int main()
{
	int x = 072;
	printf("%d/n", x + 1);
	return 0;
}
```

在C语言中，以0开头的数字被视为八进制数。因此，`072`实际上是八进制的数，转换为十进制就是`7*8 + 2 = 58`。所以，`x + 1`的结果是`58 + 1 = 59`，而不是72。这就是为什么程序的输出是59的原因。

#### 设a和b均为double型变量，且a=5.5、b=2.5，则表达式(int)a+b/b的值是(<font color=red>6.000000</font>)

将a先转成int类型，此时a=5，b/b为double类型，与int类型的a相加，int类型准换成double类型，故结果为6.000000
