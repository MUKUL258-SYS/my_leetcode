class Solution {
public:
unordered_map<string,double>mp;
void bellman(vector<vector<string>>& pairs,vector<double>& rates){
    int n=pairs.size();
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            mp[pairs[i][1]]=max(mp[pairs[i][1]],rates[i]*mp[pairs[i][0]]);
            mp[pairs[i][0]]=max(mp[pairs[i][0]],mp[pairs[i][1]]/rates[i]);
        }
    }
}
    double maxAmount(string init, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
      mp[init]=1.0;
      bellman(pairs1,rates1);
      bellman(pairs2,rates2);
      return mp[init];
        
    }
};