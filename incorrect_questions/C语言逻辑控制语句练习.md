# C语言逻辑控制语句练习

#### 若有int x,y;,执行程序段: 变量x的值最终为(<font color=red>10</font>)

```C
for(x = 1, y = 1; y< 50; y++)
{
	if (x >=10)
	{
		break;
	}
	if (x % 2 == 1)
	{
		x += 5;
		continue;
	}
	x -= 3;
}
```

当x=1时：
- 执行`x+=5`, 此时`x=6`
- 执行`continue`结束当前循环执行`for`，
- 执行`x -= 3`，此时`x = 3`，然后执行
- 执行`x += 5`, 此时`x=8`
- 执行`x -= 3`, 此时`x=5`
- 执行`x += 5`, 此时`x=10`，执行break跳出循环

#### 循环语句`while(int i = 0) i--;`的循环次数是（<font color=red>0</font>）

while语句内的判断条件值为0，就跳出循环，而while(inti =o)中inti =0返回0，故直接跳出循环，循环次数为0。

#### 以下程序的运行结果是( <font color=red>死循环</font> )

```C
int main()
{
	int n = 1;
	while (n <= 10) 
	{
		if (n % 3 == 0) continue;
		printf("%d", n++);
	}
	return 0;
}
```

当n=3时，会执行continue，结束当前循环，然后继续执行while语句，此时n还是等于3，故会陷入死循环。

#### 一句代码判断一个浮点类型变量A是否大于0

```C
if (a > 1e-7)
{
	return true;
}
else
{
	return false;
}
```

#### 下面这个程序执行后会有什么错误或者效果()

```C
#define MAX 255
int main()
{
	unsigned char A[MAX], i;
	for(i = 0; i <= MAX; i++) A[i] = i;
}
```

- **<font color=red>数组越界</font>**
- **<font color=red>死循环</font>**
- 栈溢出
- 内存泄漏

当`i=MAX`时，数组会越界，`unsigned char`型数范围为0-255，当`i>255`时，便会进入死循环，故选择AB

#### func(97)的结果是（<font color=red>编译错误</font>）

```C
int func(int a)
{
	int b = 0;
	switch(a)
	{
		case 'a':
			b = 30;
		case b':
			b = 20;
		case 97:
			b = 16;
		default:
			b = 0;
	}
	return b;
}
```

在Switch case语句中，case分支不能重复，但是a在ASCII中为97，与97重复，故编译错误

#### 调用test(10)输出结果为(<font color=red>死循环</font>)

```C
void test(int n)
{
	for(unsigned int i = 0, n >= i; n--)
	{
		printf("%d ", n);
	}
}
```

当`n>=0`时，显然`n>=i`，当n为负数时，在内存中以补码的形式存在，`n>=i`，会将n隐式转换为`unsigned int` 类型，由于`unsigned int`类型为无符号整数，故直接输出n的补码，此时n为一个正数并且值极大，所以`n>=i`恒成立，所以死循环
