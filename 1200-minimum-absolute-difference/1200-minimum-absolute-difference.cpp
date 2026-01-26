class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
       // return {{}};
        sort(arr.begin(),arr.end());
        int mini=INT_MAX;
        int n=arr.size();
        for(int i=1;i<n;i++){
            mini=min(mini,arr[i]-arr[i-1]);
        }
        vector<vector<int>>res;
        for(int i=1;i<n;i++){
            if(arr[i]-arr[i-1]==mini){
                   res.push_back({arr[i-1],arr[i]});
            }
        }
        return res;
    }
};