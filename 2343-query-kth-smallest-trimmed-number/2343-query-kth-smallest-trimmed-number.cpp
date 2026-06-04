class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n=nums[0].size();
        vector<int>v;
        for(auto q:queries){
            int k=q[0];
            int l=q[1];
            vector<pair<string,int>>vp;
            int m=0;
            for(auto &i:nums){
                string s=i;
                vp.push_back({s.substr(n-l),m});
                m++;
            }
            sort(vp.begin(),vp.end());
             v.push_back(vp[k-1].second);

        }
        return v;
    }
};