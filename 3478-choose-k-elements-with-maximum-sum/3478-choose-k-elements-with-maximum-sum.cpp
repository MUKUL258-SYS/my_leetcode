class Solution {
public:
typedef long long ll;
typedef pair<ll,ll>p;

    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<ll,vector<ll>,greater<ll>>pq;
 int n=nums1.size();
 vector<p>vp;
  for(int i=0;i<n;i++){
       vp.push_back({nums1[i],i});
 }
 sort(vp.begin(),vp.end());
 vector<long long>ans(n,0);
 ans[vp[0].second]=0;
 pq.push(nums2[vp[0].second]);
 long long sum=nums2[vp[0].second];
 for(int i=1;i<n;i++){
   // sum+=nums2[vp[i].second];
   // pq.push(nums2[vp[i].second]);
    if(vp[i].first==vp[i-1].first){
        ans[vp[i].second]=ans[vp[i-1].second];
    }
    else{
         ans[vp[i].second]=sum;
    }
     sum+=nums2[vp[i].second];
    pq.push(nums2[vp[i].second]);
    if(pq.size()>k){
        sum-=pq.top();
        pq.pop();
    }
 }
 return ans;
        
    }
};