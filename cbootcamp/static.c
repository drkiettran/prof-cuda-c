#include <stdio.h>
int func() {
    static int count = 0;
    count++;
    return count;
}

int main() {
    printf("%d\n", func());
    printf("%d\n", func());
    return 0;
}