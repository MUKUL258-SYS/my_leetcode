class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        vector<int>temp=nums;
        sort(temp.begin(),temp.end());
        if(temp==nums)return temp.size();
        int n=nums.size();
       /* vector<int>pre(n,1),post(n,1);
        int cnt=1;
        for(int i=1;i<n;i++){
                 if(nums[i]>=nums[i-1]){
                   cnt++;
                 }
                 else{
                    cnt=1;
                 }
                 pre[i]=cnt;
        }
        cnt=1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<=nums[i+1]){
                cnt++;
            }
            else{
                cnt=1;
            }
            post[i]=cnt;
        }
        for(int i=0;i<n;i++){
            cout<<pre[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            cout<<post[i]<<" ";
        }
       //   return 0;
       int maxi=0;
       for(int i=1;i<n;i++){
        if(nums[i]<nums[i-1]){
            maxi=max(maxi,pre[i-1]+1);
        }
        if(i+1<n&&(nums[i]<nums[i-1])&&(nums[i-1]<=nums[i+1])){
            maxi=max(maxi,pre[i-1]+2);
        }
       }
  return maxi;
  */
  /*int cnt=1;
     for(int i=1;i<n;i++){
          if(nums[i]>=nums[i-1]){
            cnt++;
            continue;
          }
          int j=i;
          while(j<n&&(nums[j]<nums[j-1])){
             j++;
          }
          i=j-1;
     }
     return cnt;
     */
     /*for(int i=n-2;i>=0;i--){
        if(nums[i]<=nums[i+1])nums[i]=nums[i+1];
     }
     int l=0;
     int cnt=0;
     for(int i=1;i<n;i++){
        if(nums[i]<nums[i-1])continue;
        cnt++;
        l=i;
     }
     return cnt;
     */
     stack<int>s;
     for(auto i:nums){
       // while(!s.empty()&&i)
       if(s.empty()){
        s.push(i);
        continue;
       }
       if(i<s.top())continue;
       s.push(i);
     }
     return s.size();
    }
};