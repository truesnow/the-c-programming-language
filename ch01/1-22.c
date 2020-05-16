#include <stdio.h>
#include <ctype.h>
#include <string.h>

/**
 * 练习 1-22
 * 编写一个程序，把较长的输入行“折”成短一些的两行或多行，折行的位置在输入行的第 n 列之前的最后
 * 一个非空格之后。要保证程序能够智能地处理输入行很长以及在指定的列前没有空格或制表符时的情况。
 */
#define MAX_LINE_LENGTH 10

void breakLine();
void clear(char s[]);

int main()
{
    breakLine(MAX_LINE_LENGTH);
}

/**
 * 重置字符串
 */
void clear(char s[]) {
    for (int i = 0; i < MAX_LINE_LENGTH; i++)
    {
        s[i] = '\0';
    }
}

/**
 * a 存储连续字符
 * b 存储连续空格
 * c 为当前读取字符
 * n 为每行最长字符
 * 
 * 需换行的情况：
 * - 连续字符达到 n
 * - 连续空格达到 n
 * - 连续字符 + 连续空格达到 n
 * 
 * 输出后通用处理：
 * 1. 重置 a、b、na、nb，输出时后跟换行，添加时长度也添加
 * 2. c = 换行
 * 3. c = 空格，添加 c 到 b
 * 4. c = 字符，添加 c 到 a
 * 5. 继续读取 c
 * 
 * 特殊处理情况：
 * - 字符中间含空格时，类似 `abc def12345`，需要将 b 连接到 a 后面并重置 b，然后继续处理
 * 
 * 测试用例及预期(n=10 为例)：
 * - `hello` -> `hello`
 * - `helloworld` -> `helloworld`
 * - `hello world` -> `hello worl` `d`
 * - `hello    world`（四个空格） -> `hello    w` `orld`
 * - `          `（十个空格） -> `          `（十个空格）
 * - `          hello world`（十个空格） -> `          ` `hello worl` `d`
 * - `hello\nworld` -> `hello` `world`
 */ 
void breakLine(int n) {
    // 存储连续字符
    char a[n];
    // 存储连续非可见字符（不含换行符）
    char b[n];
    // 存储到 a 的最新下标
    int na;
    // // 存储到 b 的最新下标
    int nb;
    // 当前读取字符
    char c;

    // 初始化
    na = 0;
    nb = 0;
    clear(a);
    clear(b);

    while ((c = getchar()) != EOF)
    {
        // printf("la is %d, lb is %d\n", la, lb);
        // 这里 na nb 指的是当前读取的 c 将要赋值的索引，亦可以认为是当前的 a b 内的字符长度
        if (na == n || nb == n || na + nb == n || c == '\n') {
            // 全是字符 || 全是空格 || 字符后跟空格达到长度 || 字符为换行 输出
            printf("%s%s\n", a, b);
            clear(a);
            clear(b);
            na = 0;
            nb = 0;
        }

        if (c == '\n') {
            continue;
        } else if (isgraph(c)) {
            if (nb != 0) {
                // 字符中间含空格情况，如 `abc  def`，需将 b 拷贝到 a
                strcat(a, b);
                na = na + nb;
                clear(b);
                nb = 0;
            }
            a[na++] = c;
        } else {
            b[nb++] = c;
        }

        // printf("a=-%s-,na=%d, b=-%s-, nb=%d\n", a, na, b, nb);
    }
}
