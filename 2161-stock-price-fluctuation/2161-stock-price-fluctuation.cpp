class StockPrice {
public:
unordered_map<int,int>mp;
multiset<int>s;
int l=0;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(mp[timestamp]){
          auto it=s.find(mp[timestamp]);
          s.erase(it);

        }
        mp[timestamp]=price;
        s.insert(price);
        l=max(l,timestamp);
    }
    
    int current() {
        return mp[l];
    }
    
    int maximum() {
       return *(s.rbegin()); 
    }
    
    int minimum() {
        return *(s.begin());
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