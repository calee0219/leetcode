class MedianFinder {
    priority_queue<int> left, right;
public:
    MedianFinder() {
        // left.push(INT_MIN);
        // right.push(INT_MAX);
    }
    
    void addNum(int num) {
        left.push(num);
        
        right.push(-left.top());
        left.pop();
        
        if (left.size() < right.size()) {
            left.push(-right.top());
            right.pop();
        }
        // cout << left.size() << " " << right.size() << endl;
    }
    
    double findMedian() {
        if (left.size() == right.size()) {
            return ((double)(left.top() - right.top())) / 2;
        } else {
            return left.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */