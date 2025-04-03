class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp;
        vector<int>ans;
        for(int i=0;i<n;i++){
            int len=lower_bound(dp.begin(),dp.end(),arr[i]+1)-dp.begin();
            if(len==dp.size()){
                dp.push_back(arr[i]);
            }
            else{
                dp[len]=arr[i];
            }
            ans.push_back(len+1);

        }
        return ans;
        
    }
};