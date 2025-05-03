class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        int n=responses.size();
        unordered_map<string,int>m;
        for(int i=0;i<n;i++){
            unordered_map<string,int>mp;
            for(auto j:responses[i]){
                mp[j]++;
            }
            for(auto j:mp)m[j.first]++;

            
        }
        string res;
        int maxi=0;
        for(auto i:m){
            if(i.second>maxi){
                maxi=i.second;
                res=i.first;
            }
            else if(i.second==maxi&&i.first<res){
                res=i.first;
            }
        }
        return res;
    }
};