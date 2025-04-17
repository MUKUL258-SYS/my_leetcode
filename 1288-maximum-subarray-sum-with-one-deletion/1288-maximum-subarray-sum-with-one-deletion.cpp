class Solution {
public:
int maxi;
vector<int>kadanes(vector<int>&arr){
    int n=arr.size();
    vector<int>v(n);
    int currsum=0;
    for(int i=0;i<n;i++){
        currsum=max(arr[i],currsum+arr[i]);
        maxi=max(maxi,currsum);
        v[i]=currsum;
    }
    return v;


}
    int maximumSum(vector<int>& arr) {
      int best=*max_element(arr.begin(),arr.end());
        if(best<=0)return best;
        maxi=0;
        vector<int>l=kadanes(arr);
        reverse(arr.begin(),arr.end());
        vector<int>r=kadanes(arr);
        reverse(r.begin(),r.end());
        int n=arr.size();
        best=maxi;
        for(int i=1;i<n-1;i++){
            best=max(best,l[i-1]+r[i+1]);
        }
         
         return best;
    }
};