class MedianFinder {
    priority_queue<int> left, right;
public:
    MedianFinder() {
        // left.push(INT_MIN);
        // right.push(INT_MAX);
    }
    
    void addNum(int num) {
        if (left.empty() || num < left.top()) {
            left.push(num);
        } else {
            right.push(-num);
        }
        if (left.size() > right.size() + 1) {
            right.push(-left.top());
            left.pop();
        }
        if (right.size() > left.size() + 1) {
            left.push(-right.top());
            right.pop();
        }
        // cout << left.size() << " " << right.size() << endl;
    }
    
    double findMedian() {
        if (left.size() == right.size()) {
            return ((double)(left.top() - right.top())) / 2;
        } else if (left.size() > right.size()) {
            return left.top();
        } else {
            return -right.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */