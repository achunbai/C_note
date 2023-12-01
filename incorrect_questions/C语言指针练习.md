# C语言指针练习

#### 已有变量定义和函数调用语句: `int a=25`; `print_value(&a)`; 下面函数的正确输出结果是（<font color=red>27</font>）

```C
void print value(int* x)
{
	printf("%d\n", ++(*x), (*x) = (*x) + 1, *x);
}
```

参数入栈顺序为从右往左，"%d\n"最后入栈，表示只输出一个值，即`++(*x)`，入栈时先执行`*x`,再执行`*(x)=*(x) + 1`,最后执行`++*(x)`，故此时`x`为27

#### 以下不合法的是()

```C
int f1(float);
int f2(char);
int f3(float);
int f4(float);
int (*pf)(float);
```

- `int (*p)(float) = &f1`
- `pf = &f4`
- <font color=red>pf = &f2</font>
- `pf = f3`

pf表示执行返回值为int类型，参数为float类型的函数，故C选择不合题意

**名字带`*`为指针**

指针函数
- 本身是一个函数，但返回值类型是指针
- `int* pf(float)`

函数指针
- 本身是一个指针，存的是函数的地址
- `int (*pf)(float)`

指针数组
- 本身是一个函数，但返回值类型是指针
- `int* pa[]`

数组指针
- 本身是一个指针，存的是数组的地址
- `int (*pa)[]`

#### 若有函数说明 `void fA(int m,int n)` 和指针变里的定义 `void(*p)(int,int)` 并且有 `p = fA` 则下列操作不正确的是( <font color=red>*p++</font> )

- `(*p)(3,4)`
- `p(3,4)`
- `fA(3,4)`
- <font color=red>*p++</font>

**p指向函数地址，执行完++后为野指针，取*则报错**

#### 以下程序的输出结果是( <font color=red>efgh</font> )

```C
#include <stdio.h>
int main()
{
	char* p = "abcdefgh ",* r;
	long* q;
	q = (long*)p;
	q++;
	r = (char*)q;
	printf("%s", r);
}
```

long类型占4字节，`q++`相当于`q+=sizeof(long)`;此时指向e

#### 如下代码,最终value的值是( <font color=red>2</font> )

```C
int* p1,*p2;
int value;
p1 = (int*)0x400;
p2 = (int*)0x408;
value = p2 - p1;
```

`((void*)pAddr1 -(void*)Addr2)/sizeof(type)`，type即是指针变量的类型。所以`value=p2-p1=(0x408-0x400)4 = 2`

