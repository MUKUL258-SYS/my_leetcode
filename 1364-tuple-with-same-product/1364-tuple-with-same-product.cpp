class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<long long,long long>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mp[nums[i]*nums[j]]++;
            }
        }
        long long ans=0;
        for(auto i:mp){
            int v=i.second;
            ans+=(1LL*v*(v-1)*4);
        }
        return ans;
    }
};