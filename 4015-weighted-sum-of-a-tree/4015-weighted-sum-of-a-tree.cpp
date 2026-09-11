class Solution {
public:
long long weightedSum(vector<int>& parent, vector<int>& nums) {
int n=parent.size();
vector<vector<int>>adj(n);
for(int i=1;i<n;i++){
    adj[parent[i]].push_back(i);
}
        queue<int>q;
        q.push(0);
        int l=0;
        while(!q.empty()){
            int s=q.size();
            while(s--){
            int f=q.front();
            q.pop();
            for(auto nei:adj[f]){
                q.push(nei);
            }
            }
            l++;
        }
        int tl=l;
        //cout<<tl<<endl;
        l=1;
        long long ans=0;
        q.push(0);
        while(!q.empty()){
            int s=q.size();
           // q.pop();
            while(s--){
            int f=q.front();
            q.pop();
              ans+=(1ll*(tl-l+1)*nums[f]);
            for(auto nei:adj[f]){
                //ans+=(tl-l+1)*
                q.push(nei);
            }
            }
            l++;
        }
        return ans;
    }
};