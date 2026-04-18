class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int l=1;
        int r=n-2;
        int mid=-1;
        while(l<=r){
           mid=(l+r)/2;
          if((arr[mid]>arr[mid+1]) && (arr[mid]>arr[mid-1])){
            break;
          }
          if(arr[mid]>arr[mid+1]){
            //l=mid+1;
            r=mid-1;
          }
          else l=mid+1;
        }

        return mid;
    }
};