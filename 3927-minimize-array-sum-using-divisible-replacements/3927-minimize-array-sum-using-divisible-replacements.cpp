class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        unordered_map<int,int>mp2;
        int n=nums.size();
        int maxi=0;
        for(auto i:nums){
            mp[i]=i;
            maxi=max(maxi,i);
            mp2[i]++;
        }
        if(mp[1]>0){
            return n;
        }
        unordered_map<int,int>freq;
        long long sum=0;
        for(auto i:mp2){
            int num=i.first;
          for(int j=num*2;j<=maxi;j+=num){
            if(mp[j]>0){
                mp[j]=min(mp[j],num);
            }
          }
        }
      /*  for(auto i:mp){
            cout<<i.second<<endl;
        }
        */
        for(auto i:nums){
            sum+=(1ll*mp[i]);
        }
        return sum;
    }
};