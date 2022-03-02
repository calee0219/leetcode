func isSubsequence(s string, t string) bool {
    s_idx := 0;
    for t_idx := 0; t_idx < len(t) && s_idx < len(s); t_idx += 1 {
        if s[s_idx] == t[t_idx] {
            s_idx += 1;
        }
    }
    if s_idx == len(s) {
        return true;
    }
    return false;
}
