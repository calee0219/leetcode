char findTheDifference(char * s, char * t){
    char a = 0;
    while (*s != '\0') {
        a ^= *s++;
    }
    while (*t != '\0') {
        a ^= *t++;
    }
    return (char)a;
}
