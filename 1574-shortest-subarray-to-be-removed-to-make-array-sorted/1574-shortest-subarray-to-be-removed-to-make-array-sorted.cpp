class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        vector<int>temp=arr;
        sort(temp.begin(),temp.end());
        if(temp==arr)return 0;
        int l=0;
        int r=n-1;
        while(l+1<n&&arr[l]<=arr[l+1])l++;
        while(r>=1&&(arr[r]>=arr[r-1]))r--;
        //int ans=r-l+1;
        int ans=n+1;
        ans=min(r,n-l-1);
        int i=0;
        int j=r;
        while(i<=l&&j<n){
            if(arr[i]<=arr[j]){
                ans=min(ans,j-i-1);
                i++;
            }
            else{
              j++;
            }

        }
        return ans;


        //return 0;
    }
};