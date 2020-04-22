#include <stdio.h>

/**
 * 练习 1-8
 * 编写一个统计空格、制表符与换行符个数的程序
 * 
 * 提示：命令行中 ctrl + d 为输入 EOF
 */
int main() 
{
    int space_count;
    int tab_count;
    int newline_count;

    space_count = tab_count = newline_count = 0;

    int c;
    while ((c = getchar()) != EOF)
    {
        switch (c)
        {
            case ' ':
                space_count++;
                break;
            case '\t':
                tab_count++;
                break;
            case '\n':
                newline_count++;
                break;
            default:
                break;
        }
    }
    
    printf("%s\t%s\n", "符号", "个数");
    printf("%s\t%d\n", "空格", space_count);
    printf("%s\t%d\n", "tab符", tab_count);
    printf("%s\t%d\n", "换行符", newline_count);
}
