#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * repeatLimitedString(char * s, int repeatLimit){
    // count all numbers
    int arr[26] = {};
    memset(arr, 0, sizeof(arr));
    int idx;
    for (idx = 0; s[idx] != '\0'; ++idx) {
        arr[s[idx]-'a']++;
    }
    char * newS = malloc(100001 * sizeof(char));
    int repeatTimes = 0;
    int now = 25;
    for (idx = 0; s[idx] != '\0'; ++idx) {
        while(now >= 0 && !arr[now]) {
            now--;
            repeatTimes = 0;
        }
        if (now < 0) {
            break;
        }
        //printf("%d\n", repeatTimes);
        if (repeatTimes >= repeatLimit) {
            int tmp = now-1;
            while(tmp >= 0 && !arr[tmp]) {
                tmp--;
            }
            if (tmp < 0) {
                break;
            }
            newS[idx] = 'a' + tmp;
            arr[tmp]--;
            repeatTimes = 0;
        } else {
            newS[idx] = 'a' + now;
            arr[now]--;
            repeatTimes++;
        }
    }
    newS[idx] = '\0';
    return newS;
}

int main() {
    char * str = "";
    char * nStr = repeatLimitedString(str, 2);
    printf("%s", nStr);
    free(nStr);
    return 0;
}
