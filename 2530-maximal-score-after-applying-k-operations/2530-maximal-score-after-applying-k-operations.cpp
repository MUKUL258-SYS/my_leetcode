class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long sum=0;
        unordered_map<int,int>mp;
        //sort(nums.begin(),nums.end());
        priority_queue<int>pq;
        for(auto i:nums)pq.push(i);
        while(pq.size()&&k--){
            int v=pq.top();
            pq.pop();
            int u=ceil(v/3.0);
            sum+=v;
            mp[v]--;
            if(mp[v]==0)mp.erase(v);
          if(u>0){pq.push(u);
            mp[u]++;
          }
           // pq.push()
           // pq.pop();
        }
        return sum;

    }
};