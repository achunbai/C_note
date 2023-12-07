/*
1052：计算邮资

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 116924     通过数: 56850
【题目描述】
根据邮件的重量和用户是否选择加急计算邮费。计算规则：重量在1000克以内(包括1000克), 基本费8元。超过1000克的部分，每500克加收超重费4元，不足500克部分按500克计算；如果用户选择加急，多收5元。

【输入】
输入一行，包含整数和一个字符，以一个空格分开，分别表示重量（单位为克）和是否加急。如果字符是y，说明选择加急；如果字符是n，说明不加急。

【输出】
输出一行，包含一个整数，表示邮费。

【输入样例】
1200 y
【输出样例】
17
*/

/*
#include<stdio.h>
int main()
{
    int weight;
    char isUrgent;
    scanf("%d %c",&weight,&isUrgent);
    int postage = 8;                                   //基本费8元
    if(weight > 1000)
    {
        int overweight = weight - 1000;                 //超重部分
        if(overweight % 500 == 0)
        {
            postage += overweight / 500 * 4;            //超重部分每500克加收4元
        }
        else
        {
            postage += (overweight / 500 + 1) * 4;      //不足500克部分按500克计算
        }
    }
    if(isUrgent == 'y')                                 //加急多收5元
    {
        postage += 5;
    }
    printf("%d",postage);
    return 0;
}
*/

#include <stdio.h>

int main() {
    int weight;
    char urgent;
    int fee = 8;                            //基本费8元

    scanf("%d %c", &weight, &urgent);

    if (weight > 1000) {                    //超重部分每500克加收4元
        int excess = weight - 1000;
        fee += ((excess + 499) / 500) * 4;  //不足500克部分按500克计算
    }

    if (urgent == 'y') {                    //加急多收5元
        fee += 5;
    }

    printf("%d\n", fee);

    return 0;
}