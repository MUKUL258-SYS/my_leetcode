class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        int ans=1;
        map<pair<int,int>,int>mp;
        mp[{0,0}]=-1;
        int v1=0;
        int v2=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a')v1++;
            else if(s[i]=='b')v2++;
            else{
                v1--;
                v2--;
            }
            if(mp.find({v1,v2})!=mp.end())ans=max(ans,i-mp[{v1,v2}]);
            else mp[{v1,v2}]=i;
        }
        vector<string>vp={"ab","bc","ca"};
        for(auto i:vp){
            unordered_map<int,int>m;
            char c1=i[0];
            char c2=i[1];
            int v=0;
            m[0]=-1;
            for(int k=0;k<n;k++){
                if(s[k]==c1)v++;
                else if(s[k]==c2)v--;
                else{
                    v=0;
                    m.clear();
                }
                if(m.find(v)==m.end())m[v]=k;
                else ans=max(ans,k-m[v]);
            }
        }
        int cnt=1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
             cnt++;
            }else{
               // ans=max(ans,cnt);
                cnt=1;
            }
               ans=max(ans,cnt);
        }
        return ans;
    }
};