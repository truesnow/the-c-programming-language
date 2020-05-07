#include <stdio.h>

/**
 * 练习 1-14
 * 编写一个程序，打印输入中各个字符出现频度的直方图
 */
// 数字数量
#define DIGIT_COUNT 10
// 小写字母数量
#define LOWER_COUNT 26
// 大写字母数量
#define UPPER_COUNT 26


/**
 * 打印表头
 */
void printRowHead(char c) 
{
    printf("%10c:", c);
}

/**
 * 打印数据域
 */
void printRowData(int count) 
{
    while (count-- > 0)
    {
        putchar('*');
    }
    printf("\n");
}

int main() 
{
    // 记录数字出现次数
    int digitToCountMap[DIGIT_COUNT];
    // 记录字母出现次数
    int lowerToCountMap[LOWER_COUNT];
    int upperToCountMap[UPPER_COUNT];
    // 记录其它字符出现次数
    int nOther;
    // 读取输入字符
    char c;

    nOther = 0;
    // 初始化 count 数组
    for (int i = 0; i < DIGIT_COUNT; i++)
    {
        digitToCountMap[i] = 0;
    }
    for (int i = 0; i < LOWER_COUNT; i++)
    {
        lowerToCountMap[i] = 0;
    }
    for (int i = 0; i < UPPER_COUNT; i++)
    {
        upperToCountMap[i] = 0;
    }
    
    // 读取并统计字符出现次数
    while ((c = getchar()) != EOF)
    {
        if (c >= '0' && c <= '9') {
            digitToCountMap[c - '0']++;
        } else if (c >= 'a' && c <= 'z') {
            lowerToCountMap[c - 'a']++;
        } else if (c >= 'A' && c <= 'Z') {
            upperToCountMap[c - 'A']++;
        } else {
            nOther++;
        }
    }

    // 打印直方图
    printf("各字符出现次数直方图：\n");
    if (nOther > 0) 
    {
        printf("%10s:", "other");
        printRowData(nOther);
    }
    for (int i = 0; i < DIGIT_COUNT; i++)
    {
        // 数字为 0 不打印
        int count = digitToCountMap[i];
        if (count == 0) {
            continue;
        }
        printRowHead(i + '0');
        printRowData(count);
    }
    for (int i = 0; i < LOWER_COUNT; i++)
    {
        // 数字为 0 不打印
        int count = lowerToCountMap[i];
        if (count == 0) {
            continue;
        }
        printRowHead(i + 'a');
        printRowData(count);
    }
    for (int i = 0; i < UPPER_COUNT; i++)
    {
        // 数字为 0 不打印
        int count = upperToCountMap[i];
        if (count == 0) {
            continue;
        }
        printRowHead(i + 'A');
        printRowData(count);
    }
}
