class Solution {
public:
vector<int>helper(vector<int>&v){
    int n=v.size();
    stack<int>s;
    vector<int>res(n,-1);
    for(int i=n-1;i>=0;i--){
        while(!s.empty()&& v[i]>v[s.top()]){
           res[s.top()]=i;
           s.pop();
        }
        s.push(i);
    }
    return res;

}
    long long numberOfSubarrays(vector<int>& nums) {
        
        vector<int>vp(helper(nums));
        long long ans=0;
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            auto &v=mp[nums[i]];
            v.push_back(i);
 ans+=(v.end()-upper_bound(v.begin(),v.end(),vp[i]));

        }
        return ans;
    }
};