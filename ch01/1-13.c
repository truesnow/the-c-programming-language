#include <stdio.h>

/**
 * 练习 1-13
 * 编写一个程序，打印输入中单词长度的直方图。水平方向的直方图比较容易绘制，垂直方向的直方图则要困难些
 */
// 单词最大字符数
#define WORD_MAX_LENGTH 20

/**
 * 检查是否是不可见字符
 */
int isInvisiableCharacter(int c)
{
    return c == ' ' || c == '\t' || c == '\n';
}

/**
 * 打印水平直方图
 */
void printInHorizontal(int arr[]) 
{
    printf("各单词长度数量直方图：\n");
    for (int i = 0; i < WORD_MAX_LENGTH; i++)
    {
        // 数字为 0 不打印
        int count = arr[i];
        if (count == 0) {
            continue;
        }
        printf("%3d", i);
        while (count-- > 0)
        {
            putchar('*');
        }
        printf("\n");
    }
}

/**
 * 打印垂直直方图
 */
void printInVertical(int arr[]) 
{
    // 最大数量的值
    int maxCount = 0;
    printf("各单词长度数量垂直直方图：\n");
    for (int i = 0; i < WORD_MAX_LENGTH + 1; i++)
    {
        int count = arr[i];
        if (count <= 0) {
            continue;
        }
        if (maxCount < count) {
            maxCount = count;
        }
        printf("%3d", i);
    }
    printf("\n");
    
    for (int j = 1; j < maxCount; j++)
    {
        for (int k = 0; k < WORD_MAX_LENGTH + 1; k++)
        {
            int count = arr[k];
            if (count <= 0) {
                continue;
            }
            if (count >= j) {
                printf("%3s", "*");
            } else {
                printf("%3s", "");
            }
        }
        printf("\n");
    }
    
}

int main()
{
    int c;
    int wordLenToCount[WORD_MAX_LENGTH + 1];
    int isInWord;
    int wordLen;

    isInWord = 0;
    wordLen = 0;

    for (int i = 0; i < WORD_MAX_LENGTH + 1; i++)
    {
        wordLenToCount[i] = 0;
    }
    

    while ((c = getchar()) != EOF)
    {
        if (isInvisiableCharacter(c)) 
        {
            if (wordLen <= WORD_MAX_LENGTH) 
            {
                ++wordLenToCount[wordLen];
            }
            isInWord = 0;
            wordLen = 0;
        } else
        {
            wordLen++;
            isInWord = 1;
        }
    }

    printInHorizontal(wordLenToCount);
    printInVertical(wordLenToCount);
}
