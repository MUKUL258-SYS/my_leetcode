class Solution {
public:
    long long minimumDifference(vector<int>& A) {
        int n=A.size()/3;
        int len=A.size();
        priority_queue<int>maxH;
        vector<long long>left(len);
        vector<long long>right(len);
        long long sum=0;
        for(int i=0;i<len;i++){
          maxH.push(A[i]);
          sum+=A[i];
          if(maxH.size()>n){
            sum-=maxH.top();
            maxH.pop();
          }
        if(i>=n-1){
            left[i]=sum;
        }
        }
        sum=0;
        priority_queue<int,vector<int>,greater<int>>minH;
        for(int i=len-1;i>=0;i--){
    minH.push(A[i]);
    sum+=A[i];
    if(minH.size()>n){
        sum-=minH.top();
        minH.pop();
    }
    if(i<=(len-n)){
        right[i]=sum;
    }
        }
        long long ans=LLONG_MAX;
        for(int i=n-1;i<2*n;i++){
            ans=min(ans,left[i]-right[i+1]);
        }
        return ans;
    }
};