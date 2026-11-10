class Solution {
public:
vector<int>vis;
void seive(int n){
    vis.assign(n+1,0);
    //vis[0]=0;
    //vis[1]=true;
    for(int i=2;i<=n;i++){
        if(vis[i])continue;
        for(int j=i;j<=n;j+=i){
           if(vis[j]==0)vis[j]=i;
        }
    }

   
    
}
    int longestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=0;
        for(auto i:nums){
        maxi=max(maxi,i);
        }
        seive(maxi);
        vector<vector<int>>pf(n);
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            while(x>1){
               int p=vis[x];
               pf[i].push_back(p);
               while(x%p == 0)x/=p;
            }
        }
        int l=0;
        //int cnt=0;
        int ans=0;
        unordered_map<int,int>mp;
        for(int r=0;r<n;r++){
          for(auto i:pf[r])mp[i]++;
          while(l<=r && mp.size()>k){
            for(auto j:pf[l]){
            mp[j]--;
            if(mp[j]==0)mp.erase(j);
            }
            l++;
          }
          ans=max(ans,r-l+1);

        }
        return ans;

    }
};