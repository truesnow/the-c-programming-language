#include <stdio.h>

/**
 * 练习 1-17
 * 编写一个程序，打印长度大于 80 个字符的所有输入行
 */
#define MAX_LEN 1000

int getline2(char s[], int lim);

int main()
{
    int len;
    int c;
    char str[MAX_LEN];
    while ((len = getline2(str, MAX_LEN)) > 0) {
        if (len > 80) {
            printf("String length is %d: %s\n\n\n", len, str);
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
