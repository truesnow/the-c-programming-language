#include <stdio.h>

/**
 * 练习 1-15
 * 重新编写 1.2 节中的温度转换程序，使用函数实现温度转换计算
 */
float f2c(float f) {
    return (5.0 / 9.0) * (f - 32.0);
}

int main()
{
    float f;
    int lower, upper, step;

    // 温度表的下限
    lower = 0;
    // 温度表的上限
    upper = 300;
    // 步长
    step = 20;

    f = lower;
    while (f <= upper)
    {
        printf("%3.0f %6.1f\n", f, f2c(f));
        f = f + step;
    }
    
}
