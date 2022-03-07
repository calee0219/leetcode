bool isPowerOfTwo(int n){
    if (n <= 0) {
        return false;
    }
    return (n&(n-1)) == 0;
}

/* bool isPowerOfTwo(int n){ */
/*     if (n <= 0) { */
/*         return false; */
/*     } */
/*     uint32_t c = n; */
/*     c = (c & 0x55555555) + ((c & 0xAAAAAAAA) >> 1); */
/*     c = (c & 0x33333333) + ((c & 0xCCCCCCCC) >> 2); */
/*     c = (c & 0x0F0F0F0F) + ((c & 0xF0F0F0F0) >> 4); */
/*     c = (c & 0x00FF00FF) + ((c & 0xFF00FF00) >> 8); */
/*     c = (c & 0x0000FFFF) + ((c & 0xFFFF0000) >> 16); */
/*     if (c == 1) { */
/*         return true; */
/*     } else { */
/*         return false; */
/*     } */
/* } */
