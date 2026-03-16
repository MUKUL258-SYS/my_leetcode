class Router {
    using ll = long long;
      static ll encode(int s, int d, int t){
        return (((ll)s << 47) | ((ll)d << 29) | (ll)t); 
    }

public:
int size;
unordered_map<long long,vector<int>>packets;
unordered_map<int,vector<int>>counts;
queue<long long>q;
//long long encode(int source,int destination,int timestamp){
  //  return ((long long)source<<4)|((long long)destination<<2)|timestamp;
   // return ((long long)source << 40) | ((long long)destination << 20) | timestamp;
//}
int lowerBound(vector<int>&v,int target){
    return (int)(lower_bound(v.begin(),v.end(),target)-v.begin());
}
int upperBound(vector<int>&v,int target){
    return (int)(upper_bound(v.begin(),v.end(),target)-v.begin());
}
    Router(int memoryLimit) {
         size=memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        long long key=encode(source,destination,timestamp);
        if(packets.find(key)!=packets.end())return false;
        if((int)packets.size()>=size)forwardPacket();
        packets[key]={source,destination,timestamp};
        counts[destination].push_back(timestamp);
        q.push(key);
       // if(q.size()>n)forwardPacket();
        return true;
    }
    
    vector<int> forwardPacket() {
      if(q.size()==0)return {};
      long long key=q.front();
      q.pop();
      vector<int>v=packets[key];
      int dest=v[1];
      packets.erase(key);
      counts[dest].erase(counts[dest].begin());
      return v;
    }
    
    int getCount(int destination, int startTime, int endTime) {
   auto it=counts.find(destination);
   if(it==counts.end()||it->second.empty())return 0;
        vector<int>&v=it->second;
        int l=lowerBound(v,startTime);
        int r=upperBound(v,endTime);
        return r-l;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */