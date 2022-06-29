class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>a, vector<int>b){ return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];});
        vector<int> index;
        for (int idx = 0; idx < people.size(); ++idx)
            index.push_back(idx);
        vector<vector<int>> ans (people.size(), vector<int>());
        for (auto & v: people) {
            ans[index[v[1]]] = v;
            index.erase(index.begin() + v[1]);
        }
        return ans;
    }
};