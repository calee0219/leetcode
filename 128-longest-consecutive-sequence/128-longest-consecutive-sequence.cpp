class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> unique;
        for (auto & n: nums) {
            unique.insert(n);
        }
        int ans = 0;
        for (auto n: unique) {
            if (unique.find(n-1) == unique.end()) {
                int curr = n+1;
                while (unique.find(curr) != unique.end())
                    curr += 1;
                ans = max(ans, curr-n);
            }
        }
        return ans;
    }
};