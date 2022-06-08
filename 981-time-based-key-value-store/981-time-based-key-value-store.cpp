class TimeMap {
    unordered_map<string, map<int,string>> um;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if (um.find(key) == um.end())
            um.insert({key, map<int,string>()});
        um[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (um.find(key) == um.end()) return "";
        auto it = um[key].upper_bound(timestamp);
        if (it == um[key].begin()) return "";
        it--;
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */