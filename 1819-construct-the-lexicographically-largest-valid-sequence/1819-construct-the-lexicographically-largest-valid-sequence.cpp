class Solution {
public:
string ans;
int n;
bool dfs(int idx,vector<int>&vp,vector<int>&vis){
     while(idx<vp.size()&&vp[idx]!=0){
        idx++;
     }
     if(idx==vp.size())return true;
    
    for(int i=n;i>=1;i--){
        if(vis[i])continue;
       if(i==1){
        vp[idx]=1;
        vis[i]=1;
        if(dfs(idx+1,vp,vis))return true;
        vp[idx]=0;
        vis[i]=0;
       }
       else if(idx+i<vp.size()&&vp[idx+i]==0){
            vis[i]=1;
            vp[idx]=i;
            vp[idx+i]=i;
          if(dfs(idx+1,vp,vis))return true;
            vis[i]=0;
            vp[idx]=0;
            vp[idx+i]=0;

        }
    }
    return false;
}
    vector<int> constructDistancedSequence(int n) {
        vector<int>v(2*n-1,0);
        this->n=n;
        vector<int>vis(n+1,0);
        dfs(0,v,vis);
        return v;
    }
};