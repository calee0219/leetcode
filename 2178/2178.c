#include <stdio.h>
#include <stdlib.h>

int fab(long long k, long long * arr) {
    int n = 0;
    long long count = 0;
    for(n = 0; count <= k; ++n) {
        arr[n] = (n+1) * 2;
        count += n+1;
        /* printf("%lld, %d\n", count, n); */
    }
    /* printf("%d %lld, %lld\n", n, count, arr[n-2]); */
    arr[n-2] = (k*2 - count*2 + arr[n-1] + arr[n-2]);
    return n - 1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
long long* maximumEvenSplit(long long finalSum, int* returnSize){
    if (finalSum % 2) {
        *returnSize = 0;
        return NULL;
    }
    long long * arr = malloc(100000 * sizeof(long long));
    long long tmp = finalSum / 2;
    *returnSize = fab(tmp, arr);
    //arr[(*returnSize)-1] = finalSum - arr[(*returnSize)-2];
    /* for (int idx = 0; idx < *returnSize; ++idx) { */
    /*     printf("%lld\n", arr[idx]); */
    /* } */
    return arr;
}

int main() {
    int returnSize;
    maximumEvenSplit(30, &returnSize);
    printf("%d\n", returnSize);
}
