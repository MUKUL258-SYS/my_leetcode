class Solution {
public:
vector<vector<int>>requests;
int ans;
void dfs(int i,vector<int>&indegree,int n,int cnt){
    if(i==requests.size()){
        for(int i=0;i<n;i++){
            if(indegree[i]!=0)return ;
        }
        ans=max(ans,cnt);
        return;
    }
    indegree[requests[i][0]]--;
    indegree[requests[i][1]]++;
    dfs(i+1,indegree,n,cnt+1);
    indegree[requests[i][0]]++;
    indegree[requests[i][1]]--;
    dfs(i+1,indegree,n,cnt);

}
    int maximumRequests(int n, vector<vector<int>>& requests) {
        this->requests=requests;
        vector<int>indegree(n,0);
        dfs(0,indegree,n,0);
        return ans;
    }
};