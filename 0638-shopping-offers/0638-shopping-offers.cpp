class Solution {
public:
int n;
vector<int>price,needs;
//vector<vector<int>>special;
long long solver(int idx,vector<vector<int>>&special){
    if(idx==special.size()){
          long long sum=0;
          for(int i=0;i<n;i++){
            sum+=(needs[i]*price[i]);
          } 
          return sum;
    }
    bool flag=true;
    for(int i=0;i<n;i++){
        if(special[idx][i]>needs[i]){
            flag=false;
            break;
        }
    }
    long long ans=LLONG_MAX;
    if(flag){
        for(int i=0;i<n;i++){
            needs[i]-=special[idx][i];
        }
        ans=min(ans,special[idx][n]+solver(idx,special));
        for(int i=0;i<n;i++){
            needs[i]+=special[idx][i];
        }
    ans=min(ans,solver(idx+1,special));
      return ans;
    }
    return solver(idx+1,special);

}
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        n=price.size();
        this->price=price;
        this->needs=needs;
        return solver(0,special);
    }
};