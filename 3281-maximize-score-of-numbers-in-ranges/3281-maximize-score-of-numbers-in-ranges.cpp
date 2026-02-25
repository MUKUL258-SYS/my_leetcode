class Solution {
public:
bool helper(long long mid,vector<int>&v,int d){
    int n=v.size();
   long long prev=v[0];
   for(int i=1;i<n;i++){
    long long next=max(prev+mid,1ll*v[i]);
    if(next>v[i]+d)return false;
    prev=next;
   }
   return true;
}
    int maxPossibleScore(vector<int>& start, int d) {
         long long s=0;
         long long e=2e9+1;
         sort(start.begin(),start.end());
         long long ans=s;
         while(s<=e){
            long long mid=(s+e)/2;
            if(helper(mid,start,d)){
                ans=mid;
                s=mid+1;

            }
            else{
                e=mid-1;
            }
         }
         return ans;
    }
};