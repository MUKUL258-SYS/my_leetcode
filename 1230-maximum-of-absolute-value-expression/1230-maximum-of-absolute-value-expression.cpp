class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int max1=INT_MIN,max2=INT_MIN,max3=INT_MIN,max4=INT_MIN;
        int min1=INT_MAX,min2=INT_MAX,min3=INT_MAX,min4=INT_MAX;
        vector<int>t;
        for(int i=0;i<n;i++){
          int t1=arr1[i]+arr2[i]+i;
          int t2=arr1[i]-arr2[i]+i;
          int t3=arr1[i]+arr2[i]-i;
          int t4=arr1[i]-arr2[i]-i;
          max1=max(max1,t1);
          min1=min(min1,t1);
          max2=max(max2,t2);
          min2=min(min2,t2);
          max3=max(max3,t3);
          min3=min(min3,t3);
          max4=max(max4,t4);
          min4=min(min4,t4);
        }
  t.push_back(max1-min1);
  t.push_back(max2-min2);
  t.push_back(max3-min3);
  t.push_back(max4-min4);
  sort(t.begin(),t.end(),greater<int>());
  return t[0];
    }
};