class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int m=1e9+7;
        vector<int>v,ans;
        for(int i=0;i<32;i++)
            if((n&(1<<i)))v.push_back(1<<i);
        
        for(auto i:queries){
            int j=i[0];
            long long p=v[j++];
            while(j<=i[1]){
                 p=(p*v[j])%m;
                 j++;
            }
       ans.push_back(p);
        }
        return ans;
    }
};