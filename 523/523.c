#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM 77777

struct list {
    int pos; // position
    int val; // value
    struct list * next;
};

int hash(int x) {
    return x % MAX_NUM;
}

int find(struct list * remind, int target, int position) {
    int hash_rst = hash(target);
    if (remind[hash_rst].pos != 0) {
        struct list * tmp = &remind[hash_rst];
        // Triverse colition
        while (tmp) {
            if (tmp->val == target) {
                // you may insert new node into hashtable, but we just need to check true/false
                // so we can ignore later same reminder
                return tmp->pos;
            }
            if (tmp->next == NULL) {
                break;
            }
            tmp = tmp->next;
        }
        // insert
        tmp->next = (struct list *)malloc(sizeof(struct list));
        tmp->next->val = target;
        tmp->next->pos = position;
        tmp->next->next = NULL;
        return -1;
    }
    remind[hash_rst].pos = position;
    remind[hash_rst].val = target;
    remind[hash_rst].next = NULL;
    return -1;
}

bool checkSubarraySum(int* nums, int numsSize, int k){
    if (k == 0) {
        return true;
    }
    int now = 0;
    struct list remind[MAX_NUM];
    memset(remind, 0, sizeof(struct list) * MAX_NUM);
    int idx;
    for (idx = 0; idx < numsSize; ++idx) {
        now = (now + nums[idx]) % k;
        if (now == 0 && idx != 0) {
            return true;
        }
        int tmp = find(remind, now, idx+1);
        if (tmp != -1 && idx - tmp >= 2) {
            return true;
        }
    }
    return false;
}

int main() {
    int m[] = {1,0,1,0,1};
    fprintf(stdout, "%d", checkSubarraySum(m, 5, 4));
}
