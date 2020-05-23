#include <stdio.h>

/**
 * 练习 2-5
 * 编写函数 any(s1, s2)，将字符串 s2 中的任一字符在字符串 s1 中第一次出现的位置作为结果返回。
 * 如果 s1 中不包含 s2 中的字符，返回 -1.（标准库函数 strpbrk 具有同样的功能，但它返回的是指
 * 向该位置的指针。）
 */
#define MAX 1000

int any(char s1[], char s2[]);

int main()
{
    char s1[] = "hello, world!";
    char s2[] = "dle";
    int index = any(s1, s2);

    printf("字符串 %s 第一次出现 %s 中字符的位置为: %d，字符 %c\n", s1, s2, index, index == -1 ? '\0' : s1[index]);
}

int any(char s1[], char s2[])
{
    char c;
    int i = 0;
    while ((c = s1[i++]) != '\0')
    {
        int j = 0;
        char c2;
        while ((c2 = s2[j++]) != '\0')
        {
            if (c == c2)
            {
                return i - 1;
            }
        }
    }

    return -1;
}
