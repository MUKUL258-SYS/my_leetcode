class Solution {
public:
vector<vector<int>>res;
vector<int>nums;
int n;
void dfs(int i,vector<int>&temp){
     if(i>=n){
        res.push_back(temp);
        return ;
     }
     for(int j=0;j<n;j++){
        if(temp[j]!=-69)continue;
        temp[j]=nums[i];
        dfs(i+1,temp);
        temp[j]=-69;
     }

}
    vector<vector<int>> permute(vector<int>& nums) {
      this->nums=nums;
      n=nums.size();
      vector<int>temp(n,-69);  
      dfs(0,temp);
      return res;
    }
};