class Solution {
public:
vector<int>v;

void helper(int n){
    vector<bool>vis(n+1,false);
    vis[0]=true;
    vis[1]=true;
    for(int i=2;i*i<=n;i++){
  if(vis[i])continue;
  for(int j=2*i;j<=n;j+=i){
     vis[j]=true;
  }
    }
    for(int i=0;i<=n;i++){
        if(!vis[i])v.push_back(i);
    }
}
    vector<int> maxPrimes(int n, int s) {
     //    this->s=s;
     helper(n);
     int cnt=0;
     int sum=0;
     vector<int>res;
     for(int i=0;i<v.size();i++){
        if((sum+v[i])>s ||v[i]>n)break;
        
        sum+=v[i];
        res.push_back(v[i]);
        cnt++;
     }
     return res;

    }
};