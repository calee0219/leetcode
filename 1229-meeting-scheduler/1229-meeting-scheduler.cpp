class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        int p1 = 0, p2 = 0;
        while (p1 < slots1.size() && p2 < slots2.size()) {
            if (slots1[p1][0] < slots2[p2][0]) {
                if (slots1[p1][1] > slots2[p2][0]) {
                    // intersect, start at slots2[p2][0]
                    if (min(slots1[p1][1], slots2[p2][1]) - slots2[p2][0] >= duration) {
                        return {slots2[p2][0], slots2[p2][0] + duration};
                    }
                    if (slots1[p1][1] < slots2[p2][1])
                        p1++;
                    else
                        p2++;
                } else {
                    p1++;
                }
            } else { // slots1[p1][0] >= slots2[p2][0]
                if (slots2[p2][1] > slots1[p1][0]) {
                    if (min(slots1[p1][1], slots2[p2][1]) - slots1[p1][0] >= duration) {
                        return {slots1[p1][0], slots1[p1][0] + duration};
                    }
                    if (slots1[p1][1] < slots2[p2][1])
                        p1++;
                    else
                        p2++;
                } else {
                    p2++;
                }
            }
        }
        return {};
    }
};