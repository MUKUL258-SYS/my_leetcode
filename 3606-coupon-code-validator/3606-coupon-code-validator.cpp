class Solution {
public:
bool helper(string s){
    for(auto &i:s){
        if((i>='a'&&i<='z')||(i>='A'&&i<='Z')||(i=='_')||(i>='0'&&i<='9'))continue;
        return false;
    }
    return s.size()>0;
}
    vector<string> validateCoupons(vector<string>& code, vector<string>& b, vector<bool>& isActive) {
        map<string,int>mp;
        mp["electronics"]=1;
        mp["grocery"]=2;
        mp["pharmacy"]=3;
        mp["restaurant"]=4;
        int n=code.size();
        vector<pair<int,string>>v;
        for(int i=0;i<n;i++){
            if(helper(code[i])&&(mp[b[i]]>0)&&(isActive[i])){
                v.push_back({mp[b[i]],code[i]});
            }
        }
        for(auto i:v){
            cout<<i.first<<" "<<i.second<<endl;
        }
     /*   sort(v.begin(),v.end(),[=](const  auto &v1,const auto &v2){
            if(v1.first!=v2.first){
                return v1.first<v2.first;
            }
            return v1.second<v2.second;
        });
        */
        sort(v.begin(),v.end());
        vector<string>ans;
        for(auto i:v){
            ans.push_back(i.second);
        }
        return ans;
    }
};