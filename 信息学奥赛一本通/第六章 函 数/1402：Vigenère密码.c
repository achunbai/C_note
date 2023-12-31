/*
1402：Vigenère密码

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 23670     通过数: 12571
【题目描述】
6世纪法国外交家Blaise de Vigenère设计了一种多表密码加密算法——Vigenère密码。Vigenère密码的加密解密算法简单易用，且破译难度比较高，曾在美国南北战争中为南军所广泛使用。

   在密码学中，我们称需要加密的信息为明文，用M
表示；称加密后的信息为密文，用C
表示；而密钥是一种参数，是将明文转换为密文或将密文转换为明文的算法中输入的数据，记为k
。 在Vigenère密码中，密钥k
是一个字母串，k=k1k2…kn
。当明文M=m1m2…mn
时，得到的密文C=c1c2…cn
，其中ci=mi®ki
，运算®的规则如下表所示：



Vigenère加密在操作时需要注意：

1.®运算忽略参与运算的字母的大小写，并保持字母在明文M
中的大小写形式；

2.当明文M
的长度大于密钥k
的长度时，将密钥k
重复使用。

例如，明文M=Helloworld
，密钥k=abc
时，密文C=Hfnlpyosnd
。



【输入】
第一行为一个字符串，表示密钥k
，长度不超过100
，其中仅包含大小写字母。

第二行为一个字符串，表示经加密后的密文，长度不超过1000
，其中仅包含大小写字母。

对于100%的数据，输入的密钥的长度不超过100
，输入的密文的长度不超过1000
，且都仅包含英文字母。

【输出】
输出共1行，一个字符串，表示输入密钥和密文所对应的明文。

【输入样例】
CompleteVictory
Yvqgpxaimmklongnzfwpvxmniytm
【输出样例】
Wherethereisawillthereisaway
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// 解密函数
void Decrypt(char* PlainText, char* Cipher)
{
    int CipherLen = (int)strlen(Cipher); // 获取密钥长度
    for (int i = 0; PlainText[i] != '\0'; i++) // 遍历密文
    {
        int CipherIndex = i % CipherLen; // 获取密钥中对应的字符的位置
        int CipherChar = tolower(Cipher[CipherIndex]) - 'a'; // 获取密钥中对应的字符（转为小写后）与'a'的距离
        int PlainChar = tolower(PlainText[i]) - 'a'; // 获取密文中的字符（转为小写后）与'a'的距离
        int DecryptedChar = (PlainChar - CipherChar + 26) % 26; // 计算解密后的字符与'a'的距离
        PlainText[i] = islower(PlainText[i]) ? DecryptedChar + 'a' : DecryptedChar + 'A'; // 如果原字符是小写，解密后的字符也是小写，否则是大写
    }
}

int main()
{
    char* Cipher = (char*)calloc(101, 1); // 分配存储密钥的空间
    char* PlainText = (char*)calloc(1001, 1); // 分配存储密文的空间
    scanf("%s %s", Cipher, PlainText); // 读取密钥和密文
    Decrypt(PlainText, Cipher); // 解密
    printf("%s\n", PlainText); // 输出解密后的明文
    free(PlainText); // 释放存储密文的空间
    free(Cipher); // 释放存储密钥的空间
    return 0;
}