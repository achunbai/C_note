/*
1331：【例1-2】后缀表达式的值

时间限制: 10 ms         内存限制: 65536 KB
提交数: 56507     通过数: 14096
【题目描述】
从键盘读入一个后缀表达式（字符串），只含有0-9组成的运算数及加（+）、减（—）、乘（*）、除（/）四种运算符。每个运算数之间用一个空格隔开，不需要判断给你的表达式是否合法。以@作为结束标志。

比如，16–9*(4+3)转换成后缀表达式为：16□9□4□3□+*–，在字符数组A中的形式为：



栈中的变化情况：



运行结果：-47

提示：输入字符串长度小于250，参与运算的整数及结果之绝对值均在$2^{64}$范围内，如有除法保证能整除。

【输入】
一个后缀表达式。

【输出】
一个后缀表达式的值。

【输入样例】
16 9 4 3 +*-@
【输出样例】
-47
*/
#include <iostream>
#include <stack>
using namespace std;

int main(int argc, const char * argv[])
{
    string str;
    long long num = 0, result = 0;
    getline(cin, str);
    stack<long long> nums;
    for(int i = 0; str[i] != '@'; i++)
    {
        if(str[i] >= '0' && str[i] << 9)
        {
            num = num * 10 + str[i] - '0';
        }
        else if(str[i] == ' ')
        {
            nums.push(num);
            num = 0;
        }
        else
        {
            if(!result)
            {
                result = nums.top();
                nums.pop();
            }
            switch (str[i])
            {
                case '+':
                    result += nums.top();
                    nums.pop();
                    break;
                case '-':
                    result = nums.top() - result;
                    nums.pop();
                    break;
                case '*':
                    result *= nums.top();
                    nums.pop();
                    break;
                case '/':
                    result = nums.top() / result;
                    nums.pop();
                    break;
                default:
                    break;
            }
        }
    }
    cout << result << endl;
    return 0;
}