class Solution {
public:
long long sum,k;
bool helper(long long mid,vector<int>&candies){
    long long cnt=0;
  for(auto i:candies){
    cnt+=(i/mid);
  }
  return cnt>=k;
}
    int maximumCandies(vector<int>& candies, long long k) {
        sum=0;
        this->k=k;
        for(auto i:candies)sum+=i;
        long long s=1;
        long long e=*max_element(candies.begin(),candies.end());
        long long ans=0;
        while(s<=e){
            long long mid=(s+e)/2;
            if(helper(mid,candies)){
                ans=max(ans,mid);
                s=mid+1;
            }
            else e=mid-1;
        }
        return ans;

    }
};