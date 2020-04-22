#include <stdio.h>

/**
 * 练习 1-9 
 * 编写一个将输入复制到输出的程序，并将其中连续的多个空格用一个空格代替
 */

int main()
{
    int c;
    int prev_c;

    while ((c = getchar()) != EOF)
    {
        if (prev_c == ' ' && c == ' ') {
            continue;
        }
        putchar(c);
        prev_c = c;
    }
}
