#include "stdio.h"
#include "stdbool.h"

bool reverse_w_check(int source, int target, int reserve) {
    //fprintf(stdout, "s: %d, t: %d, s*10+r: %d, r: %d\n", source, target, source*10+reserve, reserve);
    if (source == target || ((long long)source * 10 + reserve) == (long long)target) {
        return true;
    }
    if (source == 0 || ((long long)target * 10) > 0x7fffffff) {
        return false;
    }
    reserve = source % 10;
    return reverse_w_check(source / 10, target * 10 + reserve, reserve);
}

bool isPalindrome(int x){
    if (x == 0) {
        return true;
    }
    if (x & 0x80000000) { // exclude x < 0
        return false;
    }
    if (!(x % 10)) {
        return false;
    }
    if ( x > 2147447412) {
        return false;
    }

    long int source = x, target = 0;

    while (source) {
        target = target * 10 + source % 10;
        source /= 10;
    }
    return x == target;
}

int main() {
    int input;
    scanf("%d", &input);
    fprintf(stdout, "%d", isPalindrome(input));
    return 0;
}
