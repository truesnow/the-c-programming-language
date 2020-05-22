#include <stdio.h>
#include <stdio.h>

/**
 * 练习 2-4
 * 重新编写函数 squeeze(s1, s2)，将字符串 s1 中任何与字符串 s2 中字符匹配的字符都删除。
 */
int charInStr(char c, char str[]);
void squeeze(char s1[], char s2[]);

int main() {
    char s1[] = "abcdefg";
    char s2[] = "adc";
    squeeze(s1, s2);
}

/**
 * 校验字符是否在字符串中
 */
int charInStr(char c, char str[]) {
    int i = 0;
    char strc;
    while ((strc = str[i++]) != '\0')
    {
       if (c == strc) {
           return 1;
       }
    }

    return 0;
}

void squeeze(char s1[], char s2[]) {
    int i = 0;
    char s1c;
    while ((s1c = s1[i++]) != '\0')
    {
        if (!charInStr(s1c, s2)) {
            putchar(s1c);
        }
    }
}
