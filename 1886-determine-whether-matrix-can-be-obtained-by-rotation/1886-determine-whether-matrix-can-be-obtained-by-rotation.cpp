class Solution {
public:
void rotate(vector<vector<int>>&nums){
    int n=nums.size();
    vector<vector<int>>v(n,vector<int>(n));

for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      v[i][j]=nums[n-j-1][i];
    }
}
nums=v;
}
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
     int k=4;
      while(k--){
          rotate(target);
          if(target==mat)return true;
      }
      return false;  
    }
};