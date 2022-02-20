#include <stdio.h>

int check(int num) {
    int check = 0;
    while (num) {
        check += num % 10;
        num /= 10;
    }
    return !(check % 2);
}

int countEven(int num){
    int ret = 0;
    for (int i = 1; i <= num; ++i) {
        if (check(i)) {
            ret++;
        }
    }
    return ret;
}

int main() {
    for (int i = 1; i <= 1000; ++i) {
        printf("%d ", countEven(i));
    }
    return 0;
}
