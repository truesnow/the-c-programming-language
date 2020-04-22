#include <stdio.h>

/**
 * 练习 1-6
 * 验证表达式 getchar() != EOF 的值是 0 还是 1
 */

int main() {
    int i;
    i = getchar();
    printf("%d != EOF 结果是:%d\n", i, i != EOF);
}
