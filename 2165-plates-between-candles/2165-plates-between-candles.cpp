class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int>v;
        int n=s.size();
        vector<int>v2;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='|'){
            v.push_back(i);
            cnt++;

            }
            v2.push_back(cnt);
            
        }
        vector<int>ans;
        for(auto i:queries){
            int st=i[0];
            int e=i[1];
            if(e-st<=1){
               ans.push_back(0);
               continue;
            }
            int id1=lower_bound(v.begin(),v.end(),st)-v.begin();
            int id2=upper_bound(v.begin(),v.end(),e)-v.begin();
            id2--;
            cout<<v[id1]<<" "<<v[id2]<<endl;
            
            int sub;
            int num=v[id2]-v[id1]+1;
            id1=v[id1];
            id2=v[id2];
            if(id1-1>=0)sub=v2[id2]-v2[id1-1];
            else sub=v2[id2];
            if(num-sub>0)ans.push_back(num-sub);
            else ans.push_back(0);

        }
        return ans;
    }
};