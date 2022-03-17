char * toLowerCase(char * s){
    char * c = s;
    while (*c != '\0') {
        if (*c <= 'Z' && *c >= 'A') {
            // *c -= 'A' - 'a';
	    *c++ |= (1<<5);
        }
        c++;
    }
    return s;
}
