#include <stdio.h>
#include <stdlib.h>

int main() {
    char *this_course = "cisc701";
    char bad[3] = { 'b', 'a', 'd' };
    char *zero = "0";

    printf("atoi(this_course): %d\n", atoi(this_course));
    printf("atoi(bad): %d\n", atoi(bad));
    printf("atoi(zero): %d\n", atoi(zero));

    return 0;
}
