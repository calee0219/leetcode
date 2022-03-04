func rec(s, sub string, depth int, ans * []string) {
    if depth == len(s) {
        // fmt.Println("%s %d", sub, depth);
        *ans = append(*ans, sub);
        return;
    }
    if s[depth] <= '9' && s[depth] >= '0' {
        rec(s, sub+string(s[depth]), depth+1, ans);
    } else {
        if s[depth] >= 'A' && s[depth] <= 'Z' {
            // uppercase
            rec(s, sub+string(s[depth]), depth+1, ans);
            rec(s, sub+string(s[depth]-'A'+'a'), depth+1, ans);
        } else {
            // lowercase
            rec(s, sub+string(s[depth]-'a'+'A'), depth+1, ans);
            rec(s, sub+string(s[depth]), depth+1, ans);
        }
    }
}

func letterCasePermutation(s string) []string {
    var ans []string;
    rec(s, "", 0, &ans);
    return ans;
}
