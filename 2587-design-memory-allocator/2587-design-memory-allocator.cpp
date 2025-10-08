class Allocator {
public:
vector<int>memory;
int sz;
unordered_map<int,vector<int>>mp;
    Allocator(int n) {
        memory.resize(n);
        sz=n;
    }
    
    int allocate(int size, int mID) {
        int cnt=0;
        int i;
        int res=-1;
        for(i=0;i<sz;i++){
            if(memory[i]==0){
                cnt++;
                if(res==-1)res=i;
            }
            else {
                if(cnt<size)res=-1;
                cnt=0;
            }
            if(cnt>=size)break;
        }
        if(cnt<size)return -1;

     for(int idx=res;idx<res+size&&idx<sz;idx++){
        memory[idx]=mID;
        mp[mID].push_back(idx);
     }
     return res;

    }
    
    int freeMemory(int mID) {
        int cnt=0;
        for(auto i:mp[mID]){
            memory[i]=0;
            cnt++;
        }
        mp.erase(mID);
        return  cnt;
        
            }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */