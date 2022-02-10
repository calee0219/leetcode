#include <stdio.h>
#include <string.h>

int maxSubArray(int* nums, int numsSize) {
    int current_max_sum = 0, max_sum = nums[0];
    size_t idx;
    /* for (idx = 0; idx < (size_t)numsSize; ++idx) { */
    /*     current_max_sum = current_max_sum & 0x80000000 ? nums[idx] : current_max_sum + nums[idx]; */
    /*     printf("%d  %d\n", current_max_sum, max_sum); */
    /*     max_sum = current_max_sum > max_sum ? current_max_sum : max_sum; */
    /* } */
    for (idx = 0; idx < (size_t)numsSize; ++idx) {
        current_max_sum += nums[idx];
        /* max_sum = current_max_sum > max_sum ? current_max_sum : max_sum; */
        if (current_max_sum > max_sum) {
            max_sum = current_max_sum;
        }
        /* current_max_sum = current_max_sum & 0x80000000 ? 0 : current_max_sum; */
        if (current_max_sum & 0x80000000) { // if faster then = ? :, maybe due to branch prediction
            current_max_sum = 0;
        }
    }
    return max_sum;
}

int main() {
    int nums[] = {-3,-2,-2,-3};
    printf("%d", maxSubArray(nums, 4));
    return 0;
}
