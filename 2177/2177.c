#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
long long* sumOfThree(long long num, int* returnSize){
    if (num % 3) {
        *returnSize = 0;
        return NULL;
    }
    long long * ret_arr = malloc(3 * sizeof(long long));
    long long tmp = num / 3;
    ret_arr[0] = tmp -1;
    ret_arr[1] = tmp;
    ret_arr[2] = tmp+1;
    *returnSize = 3;
    return ret_arr;
}

int main() {

}
