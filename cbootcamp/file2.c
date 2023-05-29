#include <stdio.h>

void func();

int main() {
    extern int a;
    func();
    printf("%d\n", a);
}