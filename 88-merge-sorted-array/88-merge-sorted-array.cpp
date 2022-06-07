class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m-1, p2 = n-1;
        for (int idx = m+n-1; idx >= 0; --idx) {
            // cout << idx << " " << p1 << " " << p2 << endl;
            if (p1 < 0) {
                nums1[idx] = nums2[p2--];
            } else if (p2 < 0) {
                nums1[idx] = nums1[p1--];
            } else if (nums1[p1] > nums2[p2]) {
                nums1[idx] = nums1[p1--];
            } else {
                nums1[idx] = nums2[p2--];
            }
        }
    }
};