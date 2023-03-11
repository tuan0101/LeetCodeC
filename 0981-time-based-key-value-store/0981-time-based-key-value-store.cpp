class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> keyTimeMap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyTimeMap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(keyTimeMap.count(key)==0 || timestamp < keyTimeMap[key][0].first)
            return "";
        
        string value ="";
        int mid, left=0, right = keyTimeMap[key].size()-1;
        while(left<=right){
            mid = left + (right-left)/2;
            if(keyTimeMap[key][mid].first == timestamp)
                return keyTimeMap[key][mid].second;
            else if(keyTimeMap[key][mid].first < timestamp){
                value = keyTimeMap[key][mid].second;
                left = mid + 1;
            }else
                right = mid - 1;            
        }
        return value;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */