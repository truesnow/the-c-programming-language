#include <stdio.h>
#include <limits.h>
#include <math.h>

/**
 * 练习 2-1
 * 编写一个程序以确定分别由 signed 和 unsigned 限定的 char、short、int 与 long 类型变量的
 * 取值范围。采用打印标准头文件中的相应值以及直接计算两种方式实现。后一种方法的实现较困难一些，
 * 因为要确定各种浮点类型的取值范围。
 */
double getSignedMin(int bitCount);
double getSignedMax(int bitCount);
double getUnsignedMax(int bitCount);

int main()
{
    printf("使用标准头文件打印：\n");
    printf("%30s:%d, %d\n", "signed char range", CHAR_MIN, CHAR_MAX);
    printf("%30s:%d, %u\n", "unsigned char range", 0, UCHAR_MAX);
    printf("%30s:%d, %d\n", "signed short range", SHRT_MIN, SHRT_MAX);
    printf("%30s:%d, %u\n", "unsigned short range", 0, USHRT_MAX);
    printf("%30s:%d, %d\n", "signed int range", INT_MIN, INT_MAX);
    // UINT_MAX 使用 %d 会输出 -1
    printf("%30s:%d, %u\n", "unsigned int range", 0, UINT_MAX);
    printf("%30s:%ld, %ld\n", "signed long range", LONG_MIN, LONG_MAX);
    // ULONG_MAX 使用 %ld 会输出 -1
    printf("%30s:%ld, %lu\n", "unsigned long range", 0l, ULONG_MAX);

    printf("直接计算打印：\n");
    printf("%30s:%.0lf, %.0lf\n", "signed char range", getSignedMin(CHAR_BIT),
           getSignedMax(CHAR_BIT));
    printf("%30s:%d, %.0lf\n", "unsigned char range", 0, getUnsignedMax(CHAR_BIT));
    printf("%30s:%.0lf, %.0lf\n", "signed short range", getSignedMin(16),
           getSignedMax(16));
    printf("%30s:%d, %.0lf\n", "unsigned short range", 0, getUnsignedMax(16));
    printf("%30s:%.0lf, %.0lf\n", "signed int range", getSignedMin(32),
           getSignedMax(32));
    // UINT_MAX 使用 %d 会输出 -1
    printf("%30s:%d, %.0lf\n", "unsigned int range", 0, getUnsignedMax(32));
    printf("%30s:%.0lf, %.0lf\n", "signed long range", getSignedMin(64),
           getSignedMax(64));
    // ULONG_MAX 使用 %ld 会输出 -1
    printf("%30s:%ld, %.0lf\n", "unsigned long range", 0l, getUnsignedMax(64));
}

double getSignedMin(int bitCount)
{
    return -pow(2, bitCount) / 2;
}

double getSignedMax(int bitCount)
{
    return pow(2, bitCount) / 2 - 1;
}

double getUnsignedMax(int bitCount)
{
    return pow(2, bitCount) - 1;
}
