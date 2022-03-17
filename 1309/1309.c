char * freqAlphabets(char * s){
    char * ret = malloc(1001 * sizeof(char));
    char * curr = ret;
    while(*s) {
        if (*(s+1) && *(s+2) == '#') {
            *curr++ = 'a' + (*s - '0') * 10 + *(s+1) - '1';
            s += 3;
        } else {
            *curr++ = 'a' + *s - '1';
            s += 1;
        }
    }
    *curr = '\0';
    return ret;
}
