class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k) return false;
        multiset<int> st (nums.begin(), nums.end());
        while (!st.empty()) {
            int start = *st.begin();
            for (int idx = 0; idx < k; ++idx) {
                if (st.find(start+idx) == st.end())
                    return false;
                st.erase(st.find(start+idx));
            }
        }
        return true;
    }
};