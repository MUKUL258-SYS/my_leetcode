class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& s, int k) {
/* int n=prices.size();
    vector<int>pre(n,0);
    pre[0]=prices[0];
    long long sum=0;
    sum+=prices[0]*s[0];
   for(int i=1;i<n;i++){
    pre[i]=(pre[i-1]+prices[i]);
    sum+=(prices[i]*s[i]);
   }
   ////appply sliding window of ksize and decrease the sum of widow from window and add
int window_sum=0;
int sm=0;
   for(int i=0;i<k;i++){
    sm++;
    if(sm<)
   }
   for(int i=1;i+k<n;i++){
       
   }
   */
   int n=prices.size();
   vector<long long>pre(n,0);
   vector<long long>post(n,0);
   pre[0]=prices[0]*s[0];
   post[n-1]=prices[n-1]*s[n-1];
   for(int i=1;i<n;i++){
  pre[i]=(pre[i-1]+(1ll*prices[i]*s[i]));
   }
   for(int i=n-2;i>=0;i--){
    post[i]=(post[i+1]+(1ll*prices[i]*s[i]));
   }
   vector<long long>v(n),vt(n);
   v[n-1]=prices[n-1];
   int t=k/2;
   vt[n-1]=prices[n-1];
   for(int i=n-2;i>=0;i--){
    //v[i]=(v[i+1]+prices[i]);
    vt[i]=prices[i]+vt[i+1];
    v[i]=vt[i];
    if(i+t<n)v[i]-=vt[i+t];
    // v[i]=vt[i];
   }
   long long maxi=0;
   long long sum=0;
   for(int i=0;i<n;i++){
    sum+=(s[i]*prices[i]);
   }
   maxi=sum;
   //for(auto i:pre)cout<<i<<" ";
   //cout<<endl;
   //for(auto i:post)cout<<i<<" ";
   for(auto i:v){
    cout<<i<<" ";
   }
   cout<<endl;
   for(int i=0;i+k<=n;i++){
    long long sum=v[i+t];
    sum+=(i-1)>=0?pre[i-1]:0;
    sum+=(i+k)<n?post[i+k]:0;
    maxi=max(maxi,sum);
   }
   return maxi;



    }
};