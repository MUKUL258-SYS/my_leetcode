class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        sum+=nums[0];
      bool flag=true;
        long long v1;
        for(int i=1;i<n;i++){
          if(nums[i]>nums[i-1]){
            sum+=nums[i];
          }
          else{
            if(flag){
             v1=sum;
             sum=nums[i-1];
             flag=false;
            }
            sum+=nums[i];
          }
        }
      //  cout<<v1<<endl;
       // cout<<sum<<endl;
        if(v1==sum)return -1;
        else if(v1>sum)return 0;
        else return 1;
    }
};