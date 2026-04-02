class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int cnt=1;
        vector<int>pre,post;
        pre.push_back(1);
        for(int i=1;i<n;i++){
            if(nums[i]>=nums[i-1]){
                cnt++;
            }
            else{
                cnt=1;
            }
            pre.push_back(cnt);
        }
         cnt=1;
        post.push_back(1);
        for(int i=n-2;i>=0;i--){
         if(nums[i]<=nums[i+1]){
            cnt++;
         }
         else{
            cnt=1;
         }
         post.push_back(cnt);
        }
        reverse(post.begin(),post.end());
      //  for(auto i:pre)cout<<i<<" ";
       //  cout<<endl;
       // for(auto i:post)cout<<i<<" ";
        int maxi=*max_element(pre.begin(),pre.end());
        maxi=max(maxi,*max_element(post.begin(),post.end()));
        for(int i=1;i+1<n;i++){
          //  maxi=max(maxi,pre[i]);
          /*  if(nums[i]<nums[i-1]&&nums[i-1]<=nums[i+1]){
                 maxi=max(maxi,pre[i-1]+post[i+1]);
            }
            */
            if(nums[i]>=nums[i-1]&&nums[i]<=nums[i+1])continue;
          if(nums[i-1]<=nums[i+1])maxi=max(maxi,pre[i-1]+post[i+1]);
        }
        return maxi==n?maxi:maxi+1;

    }
};