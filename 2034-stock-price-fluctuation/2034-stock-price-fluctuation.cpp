struct SegNode {
  int time; // if not leaf, save right timestamp
  int min, max;
  SegNode * left;
  SegNode * right;
  SegNode(int tt, int price): time(tt), min(price), max(price), left(NULL), right(NULL) {}
};

class StockPrice {
    int current_price;
    int max_timestamp;
    unordered_map<int,multiset<int>::iterator> um; // time -> iter
    multiset<int> ms; // price
public:
    StockPrice() {
        max_timestamp = -1;
    }
    
    void update(int timestamp, int price) {
        if (timestamp >= max_timestamp) {
            max_timestamp = timestamp;
            current_price = price;
        }
        if (um.find(timestamp) == um.end()) {
            um.insert({timestamp, ms.insert(price)});
        } else {
            ms.erase(um[timestamp]);
            um[timestamp] = ms.insert(price);
        }
    }
    
    int current() {
        return current_price;
    }
    
    int maximum() {
        return *ms.rbegin();
    }
    
    int minimum() {
        return *ms.begin();
    }
};


/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */