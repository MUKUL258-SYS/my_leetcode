class Solution {
public:
vector<int> helper(int x){
    vector<int>v;
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            v.push_back(i);
            while(x%i==0)x/=i;
        }
        
    }
    if(x>1)v.push_back(x);
    return v;
}
    int minJumps(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++){
            vector<int>t=helper(nums[i]);
            for(auto j:t){
             adj[j].push_back(i);
            }
        }
        vector<int>dist(n,INT_MAX);
        dist[0]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto [dis,node]=pq.top();
            pq.pop();
            if(node+1<n&&dist[node+1]>dis+1){
                pq.push({dis+1,node+1});
                dist[node+1]=dis+1;
            }
             if(node-1>=0&&dist[node-1]>dis+1){
                pq.push({dis+1,node-1});
                dist[node-1]=dis+1;
            }
            for(auto it:adj[nums[node]]){
                if(dist[it]> 1+dis){
                    pq.push({dis+1,it});
                dist[it]=dis+1;
                }
            }
             adj[nums[node]].clear(); 
        }
        return dist[n-1];
    }
};