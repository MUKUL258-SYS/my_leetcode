class Solution {
public:
unordered_map<int,int>mp;
    int maxCount(vector<int>& banned, int n, int maxSum) {
        for(auto i:banned)mp[i]++;
        int s=0;
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(mp[i]>0)continue;
             s+=i;
          if(s>maxSum)break;
         // s+=i;
          cnt++;
        }
        return cnt;
    }
};