#include "stdio.h"

int sum_digit(int x) {
    int result = 0;
    while(x) {
        result += x % 10;
        x /= 10;
    }
    return result;
}

int countBalls(int lowLimit, int highLimit){
    int idx;
    //int max_idx = 0;
    int ans = 0;
    int arr[50] = {};
    int boxN = sum_digit(lowLimit - 1);
    for (idx = lowLimit; idx <= highLimit; ++idx) {
        if (idx % 10 == 0) {
            boxN = sum_digit(idx);
        } else {
            boxN++;
        }
        ++arr[boxN];
        //max_idx = max_idx > tmp ? max_idx : tmp;
        //ans = ans > ++arr[boxN] ? ans : arr[boxN];
    }
    for (idx = 1; idx < 50; ++idx) {
        //fprintf(stdout, "%d: %d ", idx, arr[idx]);
        //for (int tmp = 0; tmp < arr[idx]; ++tmp) {
        //    fprintf(stdout, "o");
        //}
        //fprintf(stdout, "\n");
        ans = ans > arr[idx] ? ans : arr[idx];
    }
    return ans;
}

int main() {
    int x, y;
    fscanf(stdin, "%d %d", &x, &y);
    fprintf(stdout, "\n%d\n", countBalls(x, y));
    return 0;
}
