/*
1132：石头剪子布

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 60369     通过数: 32447
【题目描述】
石头剪子布，是一种猜拳游戏。起源于中国，然后传到日本、朝鲜等地，随着亚欧贸易的不断发展它传到了欧洲，到了近现代逐渐风靡世界。简单明了的规则，使得石头剪子布没有任何规则漏洞可钻，单次玩法比拼运气，多回合玩法比拼心理博弈，使得石头剪子布这个古老的游戏同时用于“意外”与“技术”两种特性，深受世界人民喜爱。

游戏规则：石头打剪刀，布包石头，剪刀剪布。

现在，需要你写一个程序来判断石头剪子布游戏的结果。

【输入】
第一行是一个整数N
，表示一共进行了N
次游戏。1≤N≤100
。

接下来N行的每一行包括两个字符串，表示游戏参与者Player1，Player2的选择（石头、剪子或者是布）：

 S1S2
字符串之间以空格隔开S1
,S2
只可能取值在{"Rock", "Scissors", "Paper"}(大小写敏感)中。

【输出】
输出包括N
行，每一行对应一个胜利者（Player1或者Player2），或者游戏出现平局，则输出Tie。

【输入样例】
3
Rock Scissors
Paper Paper
Rock Paper
【输出样例】
Player1
Tie
Player2
*/
/*
#include <stdio.h>
#include <string.h>

int main()
{
    char round[100][2][9], result[100][8];  // 定义两个二维字符数组，round用于存储每轮的选择，result用于存储每轮的结果
    int n;  // 定义一个整数n用于存储轮数
    scanf("%d", &n);  // 从标准输入读取轮数
    for (int i = 0; i < n; i++)  // 对每一轮进行遍历
    {
        scanf("%s %s", round[i][1], round[i][2]);  // 读取每一轮的选择
        // 根据石头剪子布的规则判断每一轮的结果
        if (strcmp(round[i][1], "Rock") == 0 && strcmp(round[i][2], "Scissors") == 0)
        {
            strcpy(result[i], "Player1");
        }
        else if (strcmp(round[i][1], "Rock") == 0 && strcmp(round[i][2], "Paper") == 0)
        {
            strcpy(result[i], "Player2");
        }
        else if (strcmp(round[i][1], "Scissors") == 0 && strcmp(round[i][2], "Rock") == 0)
        {
            strcpy(result[i], "Player2");
        }
        else if (strcmp(round[i][1], "Scissors") == 0 && strcmp(round[i][2], "Paper") == 0)
        {
            strcpy(result[i], "Player1");
        }
        else if (strcmp(round[i][1], "Paper") == 0 && strcmp(round[i][2], "Rock") == 0)
        {
            strcpy(result[i], "Player1");
        }
        else if (strcmp(round[i][1], "Paper") == 0 && strcmp(round[i][2], "Scissors") == 0)
        {
            strcpy(result[i], "Player2");
        }
        else
        {
            strcpy(result[i], "Tie");
        }
    }
    for (int i = 0; i < n; i++)  // 遍历每一轮的结果
    {
        printf("%s\n", result[i]);  // 打印每一轮的结果
    }
    return 0;
}
*/
// 这段代码的主要优化点在于减少重复的字符串比较。我们可以通过将玩家的选择映射到一个整数，然后通过整数的比较来判断结果，从而减少字符串比较的次数。以下是优化后的代码：
#include <stdio.h>
#include <string.h>

// 将玩家的选择映射到一个整数
int map(char *choice) {
    if (strcmp(choice, "Rock") == 0) {  // 如果选择是"Rock"
        return 0;  // 返回0
    } else if (strcmp(choice, "Scissors") == 0) {  // 如果选择是"Scissors"
        return 1;  // 返回1
    } else {  // 如果选择是"Paper"
        return 2;  // 返回2
    }
}

int main() {
    char round[100][2][9], result[100][8];  // 定义两个二维字符数组，round用于存储每轮的选择，result用于存储每轮的结果
    int n;  // 定义一个整数n用于存储轮数
    scanf("%d", &n);  // 从标准输入读取轮数
    for (int i = 0; i < n; i++) {  // 对每一轮进行遍历
        scanf("%s %s", round[i][0], round[i][1]);  // 读取每一轮的选择
        int choice1 = map(round[i][0]);  // 将第一个玩家的选择映射到一个整数
        int choice2 = map(round[i][1]);  // 将第二个玩家的选择映射到一个整数
        if (choice1 == choice2) {  // 如果两个玩家的选择相同
            strcpy(result[i], "Tie");  // 结果是"Tie"
        } else if ((choice1 + 1) % 3 == choice2) {  // 如果第一个玩家的选择在石头剪子布的规则中胜过第二个玩家的选择
            strcpy(result[i], "Player1");  // 结果是"Player1"
        } else {  // 否则
            strcpy(result[i], "Player2");  // 结果是"Player2"
        }
    }
    for (int i = 0; i < n; i++) {  // 遍历每一轮的结果
        printf("%s\n", result[i]);  // 打印每一轮的结果
    }
    return 0;
}