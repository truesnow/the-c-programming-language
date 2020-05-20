#include <stdio.h>
#include <string.h>
#include <math.h>

/**
 * 练习 2-3
 * 编写函数 htoi(s)，把由十六进制数字组成的字符串（包含可选的前缀 `0x` 或 `0X`）转换为与之等
 * 价的整型值。字符串中允许包含的数字包括：0~9、a~f 以及 A~F。
 */
#define MAXBIT 16

int htoi(char s[]);
int getline2(char s[], int lim);

int main()
{
    int len;
    char s[MAXBIT];
    while ((len = getline2(s, MAXBIT)) > 0)
    {
        printf("十六进制%s的十进制值为：%d\n", s, htoi(s));
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

int htoi(char s[])
{
    int errcode = -1;
    int result;
    // 字符串长度
    int len = strlen(s);
    // 十六进制字符开始的指针，从 0x 或 0X 后开始转换
    int start;
    // 十六进制字符的个数
    int hexCharCount;

    if (len == 0)
    {
        printf("十六进制数为空\n");
        return errcode;
    }

    result = 0;
    if (strstr(s, "0x") != NULL || strstr(s, "0X") != NULL)
    {
        // 以 0x 或 0X 开头
        start = 2;
        hexCharCount = len - 2;
    }
    else
    {
        start = 0;
        hexCharCount = len;
    }

    if (hexCharCount <= 0)
    {
        printf("请输入准备的十六进制数\n");
        return errcode;
    }

    char c;
    while ((c = s[start++]) != '\0')
    {
        int currentCharValue = 0;
        if (c >= '0' && c <= '9')
        {
            currentCharValue = (c - '0') * (int) pow(16, (--hexCharCount));
        }
        else if (c >= 'a' && c <= 'f')
        {
            currentCharValue = (c - 'a' + 10) * (int) pow(16, (--hexCharCount));
        }
        else if (c >= 'A' && c <= 'F')
        {
            currentCharValue = (c - 'A' + 10) * (int) pow(16, (--hexCharCount));
        }
        else
        {
            printf("非法的十六进制字符：%c，字符应在 0~9、a~f 或 A-F 中\n", c);
            return errcode;
        }
        result += currentCharValue;
    }

    return result;
}
