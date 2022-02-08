#include "stdbool.h"
#include "stdio.h"

int _GCD(int a, int b) {
    /* while(a != 0 && b != 0) { */
    /*     int tmp = a; */
    /*     a = b % a; */
    /*     b = tmp; */
    /* } */
    /* return a > b ? a : b; */
    while (b) {
        b ^= a ^= (b ^= (a %= b));
    }
    return a;
}

bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity){
    return targetCapacity <= jug1Capacity + jug2Capacity &&
        targetCapacity % _GCD(jug1Capacity, jug2Capacity) == 0;
}

int main(int argc, char *argv[]) {
    int jug1Capacity, jug2Capacity, targetCapacity;
    fscanf(stdin, "%d %d %d", &jug1Capacity, &jug2Capacity, &targetCapacity);
    fprintf(stdout, "%d", canMeasureWater(jug1Capacity, jug2Capacity, targetCapacity));
    return 0;
}
