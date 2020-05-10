#include <stdio.h>

/**
 * 练习 1-19
 * 编写函数 reverse(s)，将字符串 s 中的字符顺序颠倒过来。使用该函数编写一个程序，每次颠倒一个
 * 输入行中的字符顺序
 */

#define MAX_LEN 1000

int getline2(char s[], int lim);
void reverse(char s[], char res[]);
int getLength(char s[]);

int main()
{
    char str[MAX_LEN];
    char res[MAX_LEN];
    int len;
    while ((len = getline2(str, MAX_LEN)) > 0)
    {
        reverse(str, res);
        printf("%s -> %s\n", str, res);
    }
}

/**
 * 将一行读入到 s 中并返回其长度
 */
int getline2(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        s[i] = c;
    }
    s[i] = '\0';

    return i;
}

/**
 * 获取字符串的反转字符串
 */
void reverse(char s[], char res[])
{
    int length = getLength(s);
    int j = 0;
    for (int i = length - 1; i >= 0; i--)
    {
        res[j++] = s[i];
    }
    res[j] = '\0';
}

/**
 * 获取字符串长度
 */
int getLength(char s[])
{
    char c;
    int len;
    len = 0;
    int i = 0;
    while (s[i++] != '\0')
    {
        len++;
    }

    return len;
}
