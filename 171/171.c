
int titleToNumber(char * columnTitle){
    char * current = columnTitle;
    int count = 0;
    while (*current != '\0') {
        count *= 26;
        count += *current++ - 'A' + 1;
    }
    return count;
}
