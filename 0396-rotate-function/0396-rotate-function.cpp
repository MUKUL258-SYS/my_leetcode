class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        
        vector<int>v;
        for(int i=0;i<n;i++){
            v.push_back(nums[i]);
        }
         for(int i=0;i<n;i++){
            v.push_back(nums[i]);
        }
     /*  for(auto i:v){
            cout<<i<<endl;
        }
      */  
        int k=n;
        int maxi=INT_MIN;
        int sum=0;
        int diff=0;
        for(int i=0;i<k;i++){
          sum+=(v[i]*i);
          diff+=v[i];

        }
        maxi=max(maxi,sum);

        for(int i=1;i+k<=v.size();i++){
           //sum-=((v[i-1].first)*(v[i-1].second));
           //sum+=((v[i+k-1].first)*(v[i+k-1].second));
           //diff-=v[i-1];
          // diff+=(v[i+k-1]*(k-1));
           //sum-=diff;
           //diff-v[i-1];
           sum-=(diff-v[i-1]);
           sum+=v[i+k-1]*(k-1);
         // cout<<sum<<endl;
           maxi=max(maxi,sum);
        }
        return (int)maxi;
        
        
    }
};