class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxi=-1e9;
        int mini=1e9;
        for(auto i:nums){
            maxi=max(maxi,i);
            mini=min(mini,i);
        }
        int s=maxi;
        vector<int>freq(s+1,0);
        for(auto i:nums){
          freq[i]++;
        }
        for(int i=1;i<=maxi;i++){
            freq[i]+=freq[i-1];
        }
   int ans=0;
        for(int i=mini;i<=maxi;i++){
            int f=freq[i]-freq[i-1];
            int l=max(mini,i-k);
            int r=min(maxi,i+k);
            int extra=freq[r]-freq[l-1]-f;
            extra=min(extra,numOperations);
            ans=max(ans,f+extra);
        }
        return ans;

    }
};