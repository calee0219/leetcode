class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize) return false;
        multiset<int> st (hand.begin(), hand.end());
        while (!st.empty()) {
            int start = *st.begin();
            for (int idx = 0; idx < groupSize; ++idx) {
                if (st.find(start+idx) == st.end())
                    return false;
                st.erase(st.find(start+idx));
            }
        }
        return true;
    }
};