class Solution {
public:
int ans=1e9;
int k;
void dfs(vector<int>&s,int mask,int x,int time){
    int n=s.size();
    if(mask==((1<<n)-1)){
        ans=min(ans,time);
        return ;
    }
    for(int i=0;i<n;i++){
        if(!(mask&(1<<i))){
            int cost=(s[i]+x-1)/x;
            dfs(s,mask|(1<<i),x+k,time+cost);
        }
    }
}
    int findMinimumTime(vector<int>& strength, int k) {
        sort(strength.begin(),strength.end());
        this->k=k;
        dfs(strength,0,1,0);
        return ans;
    }
};