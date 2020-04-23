#include <stdio.h>

/**
 * 练习 1-12
 * 编写一个程序，以每行一个单词的形式打印其输入。
 */
int isInvisiableCharacter(int c)
{
    return c == ' ' || c == '\t' || c == '\n';
}

int main() 
{
    int c;
    int isInWord;

    isInWord = 0;
    while ((c = getchar()) != EOF)
    {
        if (isInvisiableCharacter(c)) {
            // 当前为不可见字符
            if (isInWord) {
                // 前面为可见字符，写入换行符
                putchar('\n');
            }
            isInWord = 0;
        } else {
            // 当前为可见字符，写入该字符
            putchar(c);
            isInWord = 1;
        }
    }
    
}
