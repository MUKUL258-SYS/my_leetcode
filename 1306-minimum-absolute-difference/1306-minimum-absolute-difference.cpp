class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int mini=INT_MAX;
        int n=arr.size();
        for(int i=1;i<n;i++){
           mini=min(mini,arr[i]-arr[i-1]);
        }
        vector<vector<int>>ans;
        for(int i=1;i<n;i++){
            if(arr[i]-arr[i-1]==mini){
              ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans;
    }
};