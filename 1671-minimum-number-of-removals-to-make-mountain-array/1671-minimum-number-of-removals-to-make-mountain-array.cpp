class Solution {
public:
vector<int>nums;
int helper(int s,int e,int maxi,int inc){
   vector<int>res;
if(inc>0){
    for(int i=s;i<=e;i+=inc){
       if(nums[i]>=maxi)continue;
       if(res.empty() || nums[i]>res.back()){
        res.push_back(nums[i]);
       }
       else{
        int idx=lower_bound(res.begin(),res.end(),nums[i])-res.begin();
        res[idx]=nums[i];
       // cout<<idx<<endl;
       }
    }
}else{
     for(int i=s;i>=e;i+=inc){
       if(nums[i]>=maxi)continue;
       if(res.empty() || nums[i]>res.back()){
        res.push_back(nums[i]);
       }
       else{
        int idx=lower_bound(res.begin(),res.end(),nums[i])-res.begin();
        res[idx]=nums[i];
      //  cout<<idx<<endl;
       }
    }
}
    return res.size();
}
    int minimumMountainRemovals(vector<int>& nums) {
        int maxi=0;
        this->nums=nums;
        int n=nums.size();
        for(int i=1;i+1<n;i++){
            int len1=helper(0,i-1,nums[i],1);
            int len2=helper(n-1,i+1,nums[i],-1);
            cout<<i<<" "<<len1<<" "<<len2<<endl;
            if(len1 && len2){
                maxi=max(maxi,1+len1+len2);
            }
        }
        return n-maxi;
    }
};