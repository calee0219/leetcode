#include <stdio.h>

int countPairs(int* nums, int numsSize, int k){
    int count = 0;
    int idx1, idx2;
    for (idx1 = 0; idx1 < numsSize; ++idx1) {
        for (idx2 = idx1+1; idx2 < numsSize; ++idx2) {
            if (nums[idx1] == nums[idx2] && !((idx1 * idx2) % k)) {
                ++count;
            }
        }
    }
    return count;
}

int main() {
    int nums = {3,1,2,2,2,1,3};
    printf("%d\n", countPairs(nums, 7, 2));
    return 0;
}
