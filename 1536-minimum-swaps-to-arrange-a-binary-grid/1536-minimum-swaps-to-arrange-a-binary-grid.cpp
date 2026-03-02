class Solution {
public:
int helper(vector<int>&nums,int n){
    int cnt=0;
    for(int i=n-1;i>=0;i--){
           if(nums[i]==0)cnt++;
           else break;
    }
    return cnt;
}
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        int swaps=0;
        for(int i=0;i<n;i++){
            bool flag=false;
            int currZeros=helper(grid[i],n);
            if(currZeros>=(n-i-1))continue;
            for(int j=i+1;j<n;j++){
                int zeros=helper(grid[j],n);
                if(zeros>=(n-i-1)){
                    flag=true;
                    
                    for(int k=j;k>i;k--){
                            swaps++;
             swap(grid[k],grid[k-1]);
                    }
                    break;
                }
            }
            if(!flag)return -1;

        }
       // if(!flag)return -1;
        return swaps;
    }
};