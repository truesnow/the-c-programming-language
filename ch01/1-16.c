#include <stdio.h>

/**
 * 练习 1-16
 * 修改打印最长文本行的程序的主程序 main，使之可以打印任意长度的输入行的长度，并尽可能多地打印文本
 */
#define MAXLINE 1000 /* 允许的输入行的最大长度 */

int getline2(char line[], int maxline);

int main() 
{
    int len;/* 当前行长度 */
    char line[MAXLINE]; /* 当前的输入行 */
    
    while ((len = getline2(line, MAXLINE)) > 0) {
        printf("%d,%s", len, line);
    }
    
    return 0;
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
