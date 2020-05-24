#include <stdio.h>
#include <math.h>

/**
 * 练习 2-6
 * 编写一个函数 setbits(x, p, n, y)，该函数返回对 x 执行下列操作后的结果的值：将 x 中从第
 * p 位 开始的 n 个（二进制）位设置为 y 中最右边 n 位的值，x 的其余各位保持不变。
 */
int setbits(int x, int p, int n, int y);
int bitlen(unsigned n);
int tailnbit(unsigned m, unsigned n);

int main()
{
    printf("%d 有 %d 位二进制\n", 1, bitlen(1));
    printf("%d 有 %d 位二进制\n", 3, bitlen(3));
    printf("%d 有 %d 位二进制\n", 5, bitlen(5));

    // 1
    printf("%d 的后 %d 位二进制值为 %d\n", 5, 2, tailnbit(5, 2));
    // 3
    printf("%d 的后 %d 位二进制值为 %d\n", 7, 2, tailnbit(7, 2));
    // 5
    printf("%d 的后 %d 位二进制值为 %d\n", 13, 3, tailnbit(13, 3));

    // 9
    printf("setbits(15, 2, 2, 0) = %d\n", setbits(15, 2, 2, 0));
    // 11
    printf("setbits(15, 2, 2, 9) = %d\n", setbits(15, 2, 2, 9));
}

/**
 * 获取位数
 */
int bitlen(unsigned n)
{
    int len = 0;
    for (; n; n = n >> 1)
    {
        len++;
    }

    return len;
}

/**
 * 获取 m 的最后 n 位的值
 */
int tailnbit(unsigned m, unsigned n)
{
    return m & ((int)pow(2, n) - 1);
}

int setbits(int x, int p, int n, int y)
{
    // x 的总位数
    int xlen = bitlen(x);
    // 末尾的位数
    int taillen = xlen - p - n + 1;
    // 1 到 p 位（不含）的值：先右移 i 位，再左移 i 位，
    int i = xlen - p + 1;
    int x1p = x >> i << i;
    // 替换的值
    int replace = tailnbit(y, n) << taillen;

    return x1p + replace + tailnbit(x, taillen);
}
