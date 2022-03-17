bool isAlienSorted(char ** words, int wordsSize, char * order){
    char remap[27];
    size_t idx;
    for (idx = 0; idx < 26; ++idx) {
        remap[order[idx] - 'a'] = idx;
    }
    for (idx = 0; idx < wordsSize - 1; ++idx) {
        int ch_idx;
        // bool all_eq = true;
        for (ch_idx = 0; words[idx][ch_idx]; ++ch_idx) {
            if (!words[idx+1][ch_idx]) return false;
            int tmp = remap[words[idx][ch_idx] - 'a'] - remap[words[idx+1][ch_idx] - 'a'];
            // printf("%d ", tmp);
            if (tmp > 0) {
                return false;
            } else if (tmp < 0) {
                // all_eq = false;
                break;
            }
        }
        // if (all_eq && words[idx][ch_idx]) {
        //     return false;
        // }
    }
    return true;
}
