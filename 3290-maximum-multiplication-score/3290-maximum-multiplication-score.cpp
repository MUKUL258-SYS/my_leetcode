class Solution {
public:
vector<int>a,b;
long long dp[4][100005];
long long mini;
long long dfs(int i,int j){
    int m=b.size();
    if(i==4){
        return 0;
    }
    if(j>=m)return LLONG_MIN;
    if(dp[i][j]!=mini)return dp[i][j];
     long long op1=dfs(i,j+1);

     long long op2=dfs(i+1,j+1);
     if(op2!=LLONG_MIN){
        op2+=(1ll*a[i]*b[j]);
     }
     return dp[i][j]=max(op1,op2);
}
    long long maxScore(vector<int>& a, vector<int>& b) {
        this->a=a;
        this->b=b;
        cout<<b.size()<<endl;
        mini=-1e12;
 for(int i=0;i<4;i++){
    for(int j=0;j<100005;j++){
        dp[i][j]=mini;
    }
 }
        return dfs(0,0);
    }
};