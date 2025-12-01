class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<std::string,int>mp;
        int mini=INT_MAX;
        for(int i=n-1;i>=0;i--){
            string s=to_string(nums[i]);
            string t=s;
            reverse(t.begin(),t.end());
            int j=0;
            while(j<t.size()&&t[j]=='0')j++;
           t=t.substr(j);
            if(mp[t]>0)mini=min(mini,mp[t]-i-1);
            mp[s]=i+1;
        }
       return  mini==INT_MAX?-1:mini;
    }
};