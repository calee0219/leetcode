class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int curr = warehouse[0];
        for (int idx = 1; idx < warehouse.size(); idx++) {
            if (warehouse[idx] <= curr)
                curr = warehouse[idx];
            else
                warehouse[idx] = curr;
        }
        sort(boxes.begin(), boxes.end());
        int pos = warehouse.size()-1;
        int ans = 0;
        for (int b: boxes) {
            // cout << b << " " << pos << ":" << warehouse[pos] << endl;
            while(pos >= 0 && warehouse[pos] < b)
                pos--;
            if (pos < 0) break;
            ans++;
            pos--;
        }
        return ans;
    }
};