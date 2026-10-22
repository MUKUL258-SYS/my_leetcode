class Solution {
public:
int n,m;
vector<vector<int>>students,mentors;
int dfs(int i,vector<bool>&vis){
    if(i>=n)return 0;
    int ans=0;
    for(int j=0;j<n;j++){
   if(vis[j])continue;
    int score=0;
    for(int k=0;k<m;k++){
        if(mentors[j][k]==students[i][k])score++;
    }
    vis[j]=true;
    ans=max(ans,score+dfs(i+1,vis));
    vis[j]=false;
    }
    return ans;
}
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
      n=mentors.size();  
      m=mentors[0].size();
      this->students=students;
      this->mentors=mentors;
      vector<bool>vis(n,false);
      return dfs(0,vis);
    }
};