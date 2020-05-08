#include <stdio.h>
#include <string.h>

/**
 * 练习 1-18
 * 编写一个程序，删除每个输入行末尾的空格及制表符，并删除完全是空格的行
 */
#define MAX_LEN 1000

int getline2(char s[], int lim);
int trimTailSpaceAndTab(char res[], char s[], int len);
int getLastIndexOfSpaceOrTab(char s[], int len);
int isCharSpaceOrTab(char c);

int main()
{
    int len;
    int c;
    char str[MAX_LEN];
    while ((len = getline2(str, MAX_LEN)) > 0) {
        // 存储去除末尾空格和制表符的字符串
        char res[len];
        // 新字符串的长度
        int newlen;
        if ((newlen = trimTailSpaceAndTab(res, str, len)) > 0) {
            printf("length:%d, str is:%s", newlen, str);
        }
    }
}

/**
 * 将一行读入到 s 中并返回其长度
 */
int getline2(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}

/**
 * 删除行末尾的空格及制表符，并返回新的字符串长度
 */
int trimTailSpaceAndTab(char res[], char s[], int len) {
    int lastIndex = getLastIndexOfSpaceOrTab(s, len);
    if (lastIndex == len) {
        strcpy(res, s);
        return len;
    } else if (lastIndex == 0) {
        res[0] = '\0';
        return 0;
    } else {
        strncpy(res, s, lastIndex - 1);
        return lastIndex;
    }
}

/**
 * 返回字符串末尾最后一个空格或制表符的索引值
 * @return 0 表示整个字符串都是空格或制表符，值等于字符串长度表示结尾无空格或制表符
 *         如`hello ` 返回 5，`hello` 也返回 5
 */
int getLastIndexOfSpaceOrTab(char s[], int len) {
    // 最后一个空格或制表符的索引
    int lastIndex = len;
    // 最后一个字符为换行符，不处理
    for (int i = len - 2; i >= 0; i--)
    {
        if (isCharSpaceOrTab(s[i])) {
            lastIndex = i;
        } else {
            break;
        }
    }

    return lastIndex;
}

/**
 * 判断字符是否是空格或字符串
 */
int isCharSpaceOrTab(char c) {
    return c == ' ' || c == '\t';
}
