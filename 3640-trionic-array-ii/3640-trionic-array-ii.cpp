/*class Solution {
public:
int n;
vector<int>nums;
long long NEG = -100000000000000LL;
 long long dfs(int i,int status){
    if(i+1==n){
        if(status==3)return nums[i];
        return NEG;
    }
    long long take=NEG;
    long long nottake=NEG;
    if(status==0){
        take=max(take,nums[i]+dfs(i+1,1));
        nottake=dfs(i+1,0);
    }
   else if(status==1){
        if(nums[i+1]>nums[i]){
            take=max(take,nums[i]+dfs(i+1,1));
        }
        else if(nums[i+1]<nums[i]){
            take=max(take,nums[i]+dfs(i+1,2));
        }
    }
   else if(status==2){
       if(nums[i+1]<nums[i]){
            take=max(take,nums[i]+dfs(i+1,2));
        }
        else if(nums[i+1]>nums[i]){
            take=max(take,nums[i]+dfs(i+1,3));
        }
   }
   else if(nums[i+1]>nums[i]&&status==3){
        take=max(take,nums[i]+dfs(i+1,3));
        take = max(take, (long long)nums[i]);
    }
   return max(take,nottake);
 }
    long long maxSumTrionic(vector<int>& nums) {
      n=nums.size();  
      this->nums=nums;
      return dfs(0,0);
    }
};
*/
class Solution {
public:
    int n;
    vector<int> nums;
    long long NEG = -1e15; 
    long long memo[100005][4]; // Added memoization table

    long long dfs(int i, int status) {
        // Base Case: reach the end of the array
        if (i == n ) {
            // Valid if we finished the zig-zag (status 3)
            return (status == 3) ? 0 : NEG;
        }

        if (memo[i][status] != -1) return memo[i][status];

        long long take = NEG;
        long long nottake = NEG;

        // Choice: Not take (only allowed if we haven't started yet)
        if (status == 0) {
            nottake = dfs(i + 1, 0);
              // take = nums[i] + dfs(i + 1, 1);
        }

        // Choice: Take
        if (status == 0&&i+1<n&&nums[i+1]>nums[i]) {
            // START
            take = nums[i] + dfs(i + 1, 1);
        }
        
        else if (status == 1) {
            // UPWARD: Continue increasing or switch to decreasing
            if (i+1<n&&nums[i + 1] > nums[i]) 
                take = max(take, nums[i] + dfs(i + 1, 1));
            else if (i+1<n&&nums[i + 1] < nums[i]) 
                take = max(take, nums[i] + dfs(i + 1, 2));
        }
        else if (status == 2) {
            // DOWNWARD: Continue decreasing or switch to second upward
            if (i+1<n&&nums[i + 1] < nums[i]) 
                take = max(take, nums[i] + dfs(i + 1, 2));
            else if (i+1<n&&nums[i + 1] > nums[i]) 
                take = max(take, nums[i] + dfs(i + 1, 3));
        }
        else if (status == 3) {
            // FINAL UPWARD: Continue increasing
            if (i+1<n&&nums[i + 1] > nums[i]) 
                take = max(take, nums[i] + dfs(i + 1, 3));
            
            // Allow the sequence to end here (taking the current element)
            take = max(take, (long long)nums[i]); 
        }

        return memo[i][status] = max(take, nottake);
    }

    long long maxSumTrionic(vector<int>& nums) {
        this->n = nums.size();
        if (n == 0) return 0;
        this->nums = nums;
        
        // Initialize memo with -1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) memo[i][j] = -1;
        }

        long long result = dfs(0, 0);
        return result;
    }
};