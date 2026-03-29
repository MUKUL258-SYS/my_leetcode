class RideSharingSystem {
public:
queue<int>driver;
queue<int>rider;
unordered_map<int,int>mp;
//vector<int>helper()
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        mp[riderId]++;
        rider.push(riderId);
    }
    
    void addDriver(int driverId) {
        driver.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        while(rider.size()&&mp[rider.front()]==-1){
            rider.pop();
        }
        if(rider.size()&&driver.size()){
            vector<int>v={driver.front(),rider.front()};
            rider.pop();
            driver.pop();
            return v;
        }
        return {-1,-1};
    }
    
    void cancelRider(int riderId) {
       if(mp[riderId]>0)mp[riderId]=-1;
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */