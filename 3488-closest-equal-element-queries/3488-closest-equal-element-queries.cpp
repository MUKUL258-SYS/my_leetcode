class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        unordered_map<int,int>diff;
        int sz=1e6+9;

        // CHANGED: vector<vector<int>> -> map<int, vector<int>>
        map<int, vector<int>> v;

        int maxi=-1;

        for(int i=0;i<n;i++){
            diff[nums[i]]=sz;
            maxi=max(maxi,nums[i]);
            nums.push_back(nums[i]);
        }

        for(int i=0;i<nums.size();i++){
            v[nums[i]].push_back(i);
        }

        vector<int>ans(n,sz);

        // CHANGED: iterate over map instead of 0 → maxi
        for(auto &p : v){
            vector<int> &vec = p.second;

            for(int j=0;j<vec.size();j++){
                int idx = vec[j];
                int idx1 = j>0 ? vec[j-1] : sz+100;
                int idx2 = j+1<vec.size() ? vec[j+1] : sz+100;

                ans[idx%n]=min(ans[idx%n],abs(vec[j]-idx1));
                ans[idx%n]=min(ans[idx%n],abs(vec[j]-idx2));
            }
        }

        vector<int>res;
        for(auto i:queries){
            if(ans[i]>=n) res.push_back(-1);
            else res.push_back(ans[i]);
        }

        return res;
    }
};