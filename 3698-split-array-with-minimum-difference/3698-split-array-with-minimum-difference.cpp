class Solution {
public:
    long long splitArray(vector<int>& nums) {
        long long ans=0;
        long long sum=0;
        int n=nums.size();
        vector<pair<long long,long long>>pre(n);
        vector<pair<long long,long long>>post(n);
        pre[0]={nums[0],1};
        post[n-1]={nums[n-1],1};
        sum=pre[0].first;
        long long len=1;
        for(int i=1;i<n;i++){
             if(nums[i]>nums[i-1]){
                 sum+=nums[i];
                 len++;
             }
             else {sum=0;
               len=0;
             }
             pre[i]={sum,len};
        }
        sum=post[n-1].first;
        len=1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                sum+=nums[i];
                len++;
            }
            else {
                sum=0;
                len=0;
            }
            post[i]={sum,len};
        }
//for(auto i:pre)cout<<i.first<<" "<<i.second;
       // cout<<endl;
       // for(auto i:post)cout<<i.first<<" "<<i.second;
       // cout<<endl;
      //  return 0;
      long long mini=LLONG_MAX;
      for(int i=0;i<n-1;i++){
        if(pre[i].first==0||post[i+1].first==0)continue;
        if((pre[i].second!=(i+1))||(post[i+1].second!=(n-i-1)))continue;
           mini=min(mini,abs(pre[i].first-post[i+1].first));
      }
      return mini==LLONG_MAX?-1:mini;
    }
};