class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>pre(n,0);
        for(auto i:queries){
            pre[i[0]]++;
           if(i[1]+1<n)pre[i[1]+1]--;
        }
        int sum=0;
        for(int i=1;i<n;i++){
            pre[i]+=pre[i-1];
        }
        for(int i=0;i<n;i++){
            if(pre[i]<nums[i])return false;
        }
        return true;
    }
};