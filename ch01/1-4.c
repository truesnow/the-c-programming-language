#include <stdio.h>

/**
 * 练习 1-4
 * 编写一个程序打印摄氏温度转换为相应华氏温度的转换表
 */

/**
 * 摄氏度转华氏度
 */
float c2f(float c) {
    return 9.0 * c / 5.0 + 32.0;
}

/**
 * 摄氏度转华氏度表
 */
void c2fTable(int min, int max, int step) {
    // 华氏度
    float f;
    // 摄氏度
    float c;
    
    // 打印标题
    printf("%10s\t%10s\n", "摄氏度", "华氏度");
    c = min;
    while (c <= max) {
        f = c2f(c);
        printf("%10.2f\t%10.2f\n", c, f);
        c += step;
    }
}

int main()
{
    c2fTable(0, 300, 20);
}
