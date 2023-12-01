# C语言数组练习

#### 假定有一个数组 int a[10]，则下面存在错误的表达式为的 (<font color=red>\*a++</font>)

- `a[2]`
- **<font color=red>\*a++</font>**
- `(*a)++`
- `*(a+1)`

B选项，先`++`后取`*`，`a`为数组名是常量，所以`a++`错误;所以选B

#### 下列程序的输出结果是(<font color=red>10</font>) 

```C
#include <stdio.h>
void main()
{
	int a[] = (1,2,3,4,5,6,7,8,9,0), *p;
	p = a;
	printf("%d\n",*p + 9);
}
```

`p`指向数组首元素地址，所以`*p=1`, `1+9=10`,故选C

#### 下面程序的输出是什么(<font color=red>2 5</font>)

```C
int main( ) 
{
	int a[5] = {1, 2, 3, 4, 5};
	int *ptr = (int *)(&a + 1);
	printf("%d %d", *(a + 1), *(ptr - 1));
	return 0;
}
```

`int* ptr = (int*)(&a+1)`;`&a`是整个数组的地址，`&a+1`指向数组最一个元素的下一个元素的地址`(ptr-1)`指向数组最后一个元素; 故`(a+1)=2`, `(ptr-1)=5`

#### 下列程序的输出结果为: ( <font color=red>48 4 16 4 4 4 16 4 16 16 16</font> )

```C
#include<stdio.h>
int main()
{
	int a[3][4] = ( 0 );
	printf("%d", sizeof(a));
	printf("%d", sizeof(a[0][O]));
	printf("%d", sizeof(a[0]));
	printf("%d", sizeof(a[0] + 1));
	printf("%d", sizeof(*(a[0] + 1)));
	printf("%d",sizeof(a + 1));
	printf("%d",sizeof(*(a + 1)));
	printf("%d", sizeof(&a[0] + 1));
	printf("%d", sizeof(*(&a[0] + 1)));
	printf("%d", sizeof(*a));
	printf("%d", sizeof(a[3]));
	return 0;
}
```

#### 下列程序的输出结果为: ( <font color=red>16 4 4 4 4 4 16 4 4 4</font> )

```C
#include<stdio.h>
int main()
{
	int a[] = [ 1,2,3,4 );
	printf("%d", sizeof(a));
	printf("%d", sizeof(a + 0));
	printf("%d", sizeof(*a));
	printf("%d", sizeof(a + 1));
	printf("%d", sizeof(a[1]));
	printf("%d", sizeof(&a));
	printf("%d", sizeof(*&a));
	printf("%d", sizeof(&a + 1));
	printf("%d", sizeof(&a[0]));
	printf("%d", sizeof(&a[0] + 1));
	return 0;
}
```

#### 若有定义: `int a[]={1,2,3,4,5,6,7,8,9,10,11,12)`, `*p[3]`, `m`; 则下面程序段的输出是( <font color=red>11</font> )

```C
for (m=0; m<3; m++)
p[m] = &a[m*4];
printf("%d", P[2][2]);
```

#### 若有以下定义和语句int s[4][5],(*ps)[5]; ps=s;则对s数组元素的正确引用形式是 (<font color=red>ps[0][2]</font>)

- `ps+1`
- `*(ps+3)`
- **<font color=red>ps[0][2]</font> **
- `*(ps+1)+3`

A选项表示的是第一行地址，B选项表示的是第三行首元素的地址，D选项表示的是第一行第三个元素的地址。

#### 程序运行后的输出结果是( <font color=red>运行报错</font> )

```C
#include <stdio.h>
int main() 
{
	int a[] = (1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12), *p = a + 5, *q = NULL;
	*q =*(p+5);
	printf("%d %d\n",*p,*q);
}
```

q为NULL，*q访问空指针,运行后报错

#### 若有定义 `int a[3][5]`, `i`, `j`;(且 0≤i<3,0≤j<5)，则 `a[i][j]` 不正确的地址表示是（<font color=red>a[i] + j</font>）

- `&a[i][j]`
- **<font color=red>a[i] + j</font>**
- `*(a+i)+j`
- `*(*(a+i)+j)`

D选项，`*(*(a+i)+j)`表示的是元素`a[i][j]`的值，而非地址

#### `int x[6][4]`,`(*p)[4]`;`p = x`;则`*(p+2)`指向哪里( <font color=red>x[2][0]</font> )

- `x[0][1]`
- `x[0][2]`
- `x[1][0]`
- **<font color=red>x[2][0]</font>**

`p`为数组指针，指向数组`x`，`*(p+2)=p[2]=x[2]`, 因为此时表示第二行元素的地址，而第二行元素地址等于第二行首元素地址，故为`x[2][0]`;

