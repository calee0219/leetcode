class HitCounter {
    deque<pair<int,int>> dqp;
    int counter;
public:
    HitCounter() {
        counter = 0;
    }
    
    void hit(int timestamp) {
        if (!dqp.empty() && dqp.back().first == timestamp)
            dqp.back().second += 1;
        else
            dqp.push_back({timestamp, 1});
        counter++;
    }
    
    int getHits(int timestamp) {
        while (!dqp.empty() && dqp.front().first <= timestamp - 300) {
            counter -= dqp.front().second;
            dqp.pop_front();
        }
        return counter;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */