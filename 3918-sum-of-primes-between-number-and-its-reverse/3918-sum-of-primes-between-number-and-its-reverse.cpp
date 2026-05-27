class Solution {
public:
vector<int>v;
//int maxi=1005;
//vector<bool>vis(maxi,false);
void seive(){
    int maxi=1005;
    vector<bool>vis(maxi,true);
    vis[0]=false;
    vis[1]=false;
   for(int i=2;i<=maxi;i++){
    if(!vis[i])continue;
    for(int j=2*i;(j)<=maxi;j+=i){
        vis[j]=false;
    }
   }
   for(int i=0;i<=1000;i++){
    if(vis[i])v.push_back(i);
   }
}
    int sumOfPrimesInRange(int n) {
       // maxi=1005;
        int m=n;
        int sum=0;
        seive();
        for(auto i:v){
            cout<<i<<" ";
        }
        cout<<endl;
        while(m){
            sum=sum*10+(m%10);
            m/=10;
        }
        int mini=min(n,sum);
        int maxi=max(n,sum);
         cout<<mini<<" "<<maxi<<endl;
        int idx1=lower_bound(v.begin(),v.end(),mini)-v.begin();
        int idx2=upper_bound(v.begin(),v.end(),maxi)-v.begin();
        int res=0;
        //idx2=std::min(idx2,((int)v.size());
        idx2=std::min(idx2,(int)v.size());
        for(int i=idx1;i<idx2;i++){
            cout<<v[i]<<" ";
            res+=v[i];
        }
        return res;

    }
};