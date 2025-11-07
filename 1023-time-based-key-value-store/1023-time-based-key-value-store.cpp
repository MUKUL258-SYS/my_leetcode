class TimeMap {
public:
unordered_map<string,vector<pair<int,string>>>mp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end())return "";
        int s=0;
        int e=mp[key].size()-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(mp[key][mid].first>timestamp){
                e=mid-1;
            }
            else s=mid+1;
        }
        if(e>=0)return mp[key][e].second;
        return "";
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */