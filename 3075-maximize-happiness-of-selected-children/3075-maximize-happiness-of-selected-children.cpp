class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
       long long sum=0;
sort(h.begin(),h.end(),greater<int>());
int n=h.size();
for(int i=0;i<n;i++){
    if(k<=0)break;
    h[i]-=i;
    if(h[i]<0)continue;
    sum+=h[i];
    k--;
}
return sum;
    
    }
};