class Solution {
public:
vector<int>pre;
int m;
int dp[105][105];
bool dfs(int s,int e){
    if((e-s+1)==2){
        return true;
    }
    if(dp[s][e]!=-1)return dp[s][e];

   // bool res=false;
  /*  for(int i=s;i<=e;i++){
         int v1=-1;
         if(i!=e)v1=pre[i]-(s-1>=0?pre[s-1]:0);
         int v2=pre[e]-pre[i];
         if((i-s+1)==1 && v2>=m){
            res=res||(dfs(s,i)&&dfs(i+1,e));
         }
         if((e-i+1)==1){
            res=res||(dfs(i,e-1)&&dfs(e,e));
         }
         
         if(v1>=m && v2>=m){
              res=res||(dfs(s,i)&&dfs(i+1,e));
         }
    }
    */
    bool res=false;
    int v1=pre[e]-pre[s];
    int v2=pre[e-1]-(s-1>=0?pre[s-1]:0);
    //cout<<v1<<" "<<v2<<endl;
    if(v1>=m){
        res=res||dfs(s+1,e);
    }
    if(v2>=m){
        res=res||dfs(s,e-1);
    }
    return dp[s][e]=res;
}
    bool canSplitArray(vector<int>& nums, int m) {
        int n=nums.size();
        if(n==1||n==2)return true;
     pre.resize(n);
     pre[0]=nums[0];
     this->m=m;
     for(int i=1;i<n;i++){
        pre[i]=pre[i-1]+nums[i];
     }
  memset(dp,-1,sizeof(dp));

 return  dfs(0,n-1);
        
    }
};