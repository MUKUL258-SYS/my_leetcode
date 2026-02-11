class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        int n=nums.size();

       // int lessThan[n+1][n+1];
       vector<vector<int>>lessThan(n+5,vector<int>(n+5,0));
        for(int i=0;i<=n;i++)lessThan[i][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=n;j++){
                lessThan[j][i]=lessThan[j][i-1]+(nums[i-1]<j);
            }
        }
        long long res=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]>nums[j]){
                    long long g=n-nums[i]-(j-lessThan[nums[i]][j+1]);
                    long long l=lessThan[nums[j]][i+1];
                    res+=(g*l);
                }
            }
        }
        return res;
    }
};