class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 1;
        unordered_set<int>v;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
              v.insert(nums[i]^nums[j]);
            }
        }
        unordered_set<int>s;
        for(int i=0;i<n;i++){
           for(auto j:v){
            int ans=nums[i]^j;
            if(s.contains(ans))continue;
               s.insert(ans);
           }
        }
        return s.size();

    }
};