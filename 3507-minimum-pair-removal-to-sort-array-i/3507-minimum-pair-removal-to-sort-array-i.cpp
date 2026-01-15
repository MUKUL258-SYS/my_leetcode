class Solution {
public:
bool issorted(vector<int>&v){
    int n=v.size();
    for(int i=0;i+1<n;i++){
        if(v[i]>v[i+1])return false;
    }
    return true;
}
    int minimumPairRemoval(vector<int>& nums) {
        vector<int>temp=nums;
        sort(temp.begin(),temp.end());
        if(temp==nums)return 0;
        //int mini=INT_MAX;
        int n=nums.size();
        int cnt=0;
        while(true){
            if(issorted(nums))break;
            cnt++;
            int mini=INT_MAX;
           /* vector<int>v;
            for(auto i:nums)if(i!=-1)v.push_back(i);
            nums=v;
            */
            n=nums.size();
            for(int i=0;i+1<n;i++){
             //   if(nums[i]==-1)continue;
                if(nums[i]+nums[i+1]<mini)mini=nums[i]+nums[i+1];

            }
            for(int i=0;i+1<n;i++){
                if((nums[i]+nums[i+1])==mini){
                    nums[i]=mini;
                    nums[i+1]=-3005;
                    break;
                }
            }
             vector<int>v;
            for(auto i:nums)if(i!=-3005)v.push_back(i);
            nums=v;
        }
        return cnt;
        

    }
};