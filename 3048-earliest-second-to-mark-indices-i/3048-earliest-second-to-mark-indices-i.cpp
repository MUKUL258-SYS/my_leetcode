class Solution {
public:
vector<int>nums,ci;
long long sum;
bool helper(int idx){
    int n=nums.size();
   if(idx<(sum-1))return false;
   unordered_map<int,int>mp;
   for(int i=0;i<=idx;i++){
    mp[ci[i]]=i;
}
if(mp.size()!=n)return false;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
for(auto i:mp){
    pq.push({i.second,nums[i.first]});
}
int time=0;
while(pq.size()){
    auto [lastOccur,t]=pq.top();
    pq.pop();
    if(lastOccur-time<t)return false;
    time+=(t+1);

}
return true;

}
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& ci) {
        int n=nums.size();
        this->nums=nums;
       // this->ci=ci;
        int m=ci.size();
        for(int i=0;i<m;i++)ci[i]--;
        this->ci=ci;
    sum=0;
   int ans=-1;
   for(auto i:nums)sum+=i;
   long long s=0;
   long long e=m-1;
   while(s<=e){
    int mid=(s+e)/2;
    if(helper(mid)){
       ans=mid+1;
       e=mid-1;
    }
    else{
       s=mid+1;
    }
   }
   return ans;
    }
};