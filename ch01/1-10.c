#include <stdio.h>

/**
 * 练习 1-10
 * 编写一个将输入复制到输出的程序，并将其中的制表符替换为 \t，把回退符替换为 \b，把反斜杠替换
 * 为 \\。这样可以将制表符和回退符以可见的方式显示出来
 */

int main()
{
    int c;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t') {
            putchar('\\');
            putchar('t');
        } else if (c == '\b') {
            putchar('\\');
            putchar('b');
        } else if (c == '\\') {
            putchar('\\');
            putchar('\\');
        } else {
            putchar(c);
        }
    }
}
