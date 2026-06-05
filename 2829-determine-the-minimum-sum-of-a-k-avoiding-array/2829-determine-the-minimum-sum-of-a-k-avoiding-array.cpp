class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_map<int,int>mp;
        int sum=0;
        int i=1;
        int cnt=1;
       while(true){
        if(cnt>n)break;
       // if(mp[i]>0)continue;
       if(mp[i]==0){
        sum+=i;
        mp[k-i]++;
        cnt++;
       }
       i++;

       }
      /* for(auto i:mp){
        cout<<i.first<<endl;
       }
       */
       return sum;
    }
};