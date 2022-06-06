#define LS 10000
int TG;

struct ST{
    int pos;
    int speed;
    int step;
    ST():pos(0),speed(0),step(0) {}
    ST(int p, int s, int st):pos(p),speed(s),step(st) {}
};

struct CMP {
    bool operator() (ST a, ST b) { return (a.step + abs(TG - a.pos)) > (b.step + abs(TG - b.pos)); }
    // bool operator() (ST a, ST b) { return (a.step) > (b.step); }
};

class Solution {
public:
    int racecar(int target) {
        if (target == 0) return 0;
        TG = target;
        // bfs
        set<pair<int,int>> us; // position,speed
        us.insert({0,1});
        // auto cmp = [](ST a, ST b) { return (a.step + TG - a.pos) < (b.step + TG - b.pos); };
        // priority_queue<ST, vector<ST>, CMP> pq;
        queue<ST> pq;
        pq.push(ST{0,1,0});
        while (!pq.empty()) {
            // ST curr = pq.top();
            ST curr = pq.front();
            pq.pop();
            // R
            if (curr.speed > 0 && us.find({curr.pos, -1}) == us.end()) {
                us.insert({curr.pos, -1});
                pq.push(ST{curr.pos, -1, curr.step+1});
            } else if (curr.speed < 0 && us.find({curr.pos, 1}) == us.end()) {
                us.insert({curr.pos, 1});
                pq.push(ST{curr.pos, 1, curr.step+1});
            }
            // A
            if (curr.pos+curr.speed <= LS && curr.pos+curr.speed >= -20 &&
                (curr.speed * 2) <= LS && (curr.speed * 2) >= -LS &&
                us.find({curr.pos+curr.speed, curr.speed * 2}) == us.end()) {
                if (curr.pos + curr.speed == target) return curr.step+1;
                us.insert({curr.pos+curr.speed, curr.speed * 2});
                pq.push(ST{curr.pos+curr.speed, curr.speed * 2, curr.step+1});
            }
        }
        return -1;
    }
};