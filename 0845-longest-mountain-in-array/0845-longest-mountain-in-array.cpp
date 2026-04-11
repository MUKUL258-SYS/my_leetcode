class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        vector<int>pre;
        pre.push_back(1);
        vector<int>post;
        //pre.push_back(1);
        post.push_back(1);
        
        int cnt=1;
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
              cnt++;
            }
            else{
                //pre[i-1]=cnt;
                cnt=1;
            }
            pre.push_back(cnt);

        }
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                cnt++;
            }
            else{
                cnt=1;
            }
            post.push_back(cnt);
        }
        reverse(post.begin(),post.end());
        
       int maxi=0;
       for(int i=0;i<n;i++){
          int value=pre[i]+post[i]-1;
          if(value>=3&&pre[i]>=2&&post[i]>=2)
           maxi=max(maxi,value);
       }
      return maxi;
    }
};