class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int mod=1e9+7;
        vector<int>left(n,-1),right(n,n);
        stack<int>s;
        for(int i=0;i<n;i++){
            while(!s.empty()&&arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.size()){
                left[i]=s.top();
            }
            s.push(i);
        }
        while(s.size())s.pop();
        for(int i=n-1;i>=0;i--){
            while(!s.empty()&&arr[s.top()]>arr[i]){
                s.pop();
            }
            if(s.size()){
                right[i]=s.top();
            }
            s.push(i);
        }

        long long sum=0;
        for(int i=0;i<n;i++){
            long long a=i-left[i];
            long long b=right[i]-i;
            sum=(sum+(arr[i]*(a*b)%mod)%mod)%mod;
        }
        return sum;
    }
};