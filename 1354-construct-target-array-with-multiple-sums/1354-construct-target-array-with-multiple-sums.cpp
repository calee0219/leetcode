class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long int sum = 0;
        priority_queue<int> pq;
        for (int t: target) {
            sum += t;
            pq.push(t);
        }
        while (pq.top() > 1) {
            int m = pq.top();
            pq.pop();
            long long int other = sum - m;
            // cout << m << " " << other << endl;
            if (other == 1) break;
            if (m <= other) return false;
            if (other == 0 || (m % other) == 0) return false;
            pq.push(m % other);
            sum = sum - m + (m % other);
        }
        return true;
    }
};