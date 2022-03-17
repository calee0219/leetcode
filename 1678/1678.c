

char * interpret(char * command){
    char * arr = malloc(102 * sizeof(char));
    size_t idx = 0;
    size_t cmd_idx = 0;
    while (command[cmd_idx] != '\0') {
        // printf("%d %d\n", idx, cmd_idx);
        switch (command[cmd_idx++]) {
            case 'G':
                arr[idx++] = 'G';
                break;
            case '(':
                if (command[cmd_idx++] == ')') {
                    arr[idx++] = 'o';
                } else {
                    arr[idx++] = 'a';
                    arr[idx++] = 'l';
                    cmd_idx += 2;
                }
                break;
        }
    }
    // printf("%d %d\n", idx, cmd_idx);
    arr[idx] = '\0';
    return arr;
}
