#include <stdio.h>
#include <string.h>

/**
 * 练习 1-23
 * 编写一个删除 C 语言程序中所有的注释语句的程序。要正确处理带引号的字符串与字符常量。在 C 语言
 * 中，注释不允许嵌套
 */
void removeComment();

int main()
{
    removeComment();
}

/**
 * 注释类型包含
 * - 单行 // 注释
 * - 多行注释
 */
void removeComment()
{
    char c;
    char prevc;
    char nextc;

    while ((c = getchar()) != EOF)
    {
        if (c == '"')
        {
            putchar(prevc = c);
            // 引号中出现的注释字符忽略
            while ((c = getchar()) != '"')
            {
                putchar(prevc = c);
            }
            putchar(prevc = c);
        }
        else if (c == '/')
        {
            // 可能是注释，这里先不写入 c
            nextc = getchar();
            if (nextc == '/')
            {
                // 单行注释
                while ((c = getchar()) != '\n')
                {
                    // 只要不是换行，该单行注释忽略
                    ;
                }
                putchar('\n');
            }
            else if (nextc == '*')
            {
                // /* 注释
                prevc = getchar();
                while ((c = getchar()) != '/' || prevc != '*')
                {
                    // 直到遇到 */
                    prevc = c;
                }
            }
            else
            {
                // 不是注释，写入 c
                putchar(c);
                putchar(prevc = nextc);
            }
        }
        else
        {
            putchar(prevc = c);
        }
    }
}
