class Solution {
public:
vector<vector<int>>requests;
int n,m;

int ans;
void dfs(int i,vector<int>&vp,int cnt){
    if(i==m){
          for(int ii=0;ii<n;ii++){
            if(vp[ii]!=0)return ;
          }
       ans=max(ans,cnt);
       return;
    }
    vp[requests[i][0]]--;
    vp[requests[i][1]]++;
    dfs(i+1,vp,cnt+1);
    vp[requests[i][0]]++;
    vp[requests[i][1]]--;
    dfs(i+1,vp,cnt);
}
    int maximumRequests(int n, vector<vector<int>>& requests) {
        this->requests=requests;
        this->n=n;
        m=requests.size();
        vector<int>vp(n,0);
        ans=0;
        dfs(0,vp,0);
        return ans;
    }
};