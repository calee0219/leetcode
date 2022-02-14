#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int minimumOperations(int* nums, int numsSize){
    if (numsSize < 2) {
        return 0;
    }
    // count odd index and even index
    int most1[2] = {0,0}, most2[2] = {0,0};
    int count[2][100001]; // count[0][x] for even, count[1][x] for odd
    memset(count, 0, sizeof(count));
    int idx;
    for (idx = 0; idx < numsSize; ++idx) {
        int n = nums[idx];
        int eo = idx & 1;
        ++count[eo][n];
        if (n == most1[eo]) {
            continue;
        } else if (count[eo][n] > count[eo][most1[eo]]) {
            most2[eo] = most1[eo];
            most1[eo] = n;
        } else if (count[eo][n] > count[eo][most2[eo]]) {
            most2[eo] = n;
        }
        /* printf("%d: %d %d\n", n, counto[n], counte[n]); */
        /* printf("o: %d %d, e: %d %d\n", odd1, odd2, even1, even2); */
    }
    if (most1[0] == most1[1]) {
        if (count[0][most1[0]] + count[1][most2[1]] > count[0][most2[0]] + count[1][most1[1]]) {
            return numsSize - count[0][most1[0]] - count[1][most2[1]];
        } else {
            return numsSize - count[0][most2[0]] - count[1][most1[1]];
        }
    }
    return numsSize - count[0][most1[0]] - count[1][most1[1]];
}

int main() {
    int nums[] = {3,3,3,3,3,3,3};
    printf("%d", minimumOperations(nums,7));
}
