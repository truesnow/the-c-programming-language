#include <stdio.h>

/**
 * 练习 1-3
 * 修改温度转换程序，使之能在转换表的顶部打印一个标题
 */

/**
 * 华氏度转摄氏度
 */
float f2c(float f) {
    return 5.0 * (f - 32.0) / 9.0;
}

/**
 * 华氏度转摄氏度表
 */
void f2cTable(int min, int max, int step) {
    // 华氏度
    float f;
    // 摄氏度
    float c;
    
    // 打印标题
    printf("%10s\t%10s\n", "华氏度", "摄氏度");
    f = min;
    while (f <= max) {
        c = f2c(f);
        printf("%10.2f\t%10.2f\n", f, c);
        f += step;
    }
}

int main()
{
    f2cTable(0, 300, 20);
}
