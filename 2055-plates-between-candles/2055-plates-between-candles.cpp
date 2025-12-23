class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n=s.size(),cnt=0;
        vector<int>pre(n,0),cp,ans;
        for(int i=0;i<n;i++){
            if(s[i]=='*')cnt++;
            if(s[i]=='|')cp.push_back(i);
            pre[i]=cnt;
        }
        for(auto i:queries){
            int st=i[0];
            int et=i[1];
            int l=lower_bound(cp.begin(),cp.end(),st)-cp.begin();
            int r=upper_bound(cp.begin(),cp.end(),et)-cp.begin()-1;

           if(l>=r){
                ans.push_back(0);
            }
            else ans.push_back(pre[cp[r]]-pre[cp[l]]);
        }
        return ans;
    }
};