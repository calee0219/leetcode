class MyCalendar {
    map<int,int> tree;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        cout << start << " " << end << " ";
        auto it = tree.upper_bound(start);
        if (it == tree.begin() && it == tree.end()) {
            tree.insert({start, end});
            return true;
        }
        if (it != tree.end()) {
            auto next = it;
            cout << " " << next->first << " " << end << " ";
            if (next->first < end) {
                cout << "(1)" << endl;
                return false;
            }
        }
        if (it != tree.begin()) {
            auto prev = it;
            prev--;
            if (prev->second > start) {
                cout << "(2)" << endl;
                return false;
            }
        }
        tree.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */