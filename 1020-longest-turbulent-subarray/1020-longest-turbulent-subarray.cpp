class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        int r=1;
        int l=0;
        string prev="";
        int ans=1;
        while(r<n){
            if(arr[r]>arr[r-1]&&prev!=">"){
                ans=max(ans,r-l+1);
                r++;
                prev=">";
            }
            else if(arr[r]<arr[r-1]&&prev!="<"){
                 ans=max(ans,r-l+1);
                  r++;
                  prev="<";

            }
            else{
                r=(arr[r]==arr[r-1])?r+1:r;
                l=r-1;
                prev="";

            }
        }
        return ans;
    }
};