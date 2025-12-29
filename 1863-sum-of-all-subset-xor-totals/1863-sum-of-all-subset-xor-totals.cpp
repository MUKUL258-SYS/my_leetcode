class Solution {
public:
int dfs(int i,vector<int>&nums,int curr){
    int n=nums.size();
    if(i>=n)return curr;
    int take=0,notake=0;
    take=(dfs(i+1,nums,curr^nums[i]));
    notake=dfs(i+1,nums,curr);
    return take+notake;
}
    int subsetXORSum(vector<int>& nums) {
        /*int n=nums.size();
        int sum=0;
        for(int i=0;i<(1<<n);i++){
            int x=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                     x=x^nums[j];
                }
            }
            sum+=x;

        }
        return sum;
        */
       return dfs(0,nums,0);
    }
};