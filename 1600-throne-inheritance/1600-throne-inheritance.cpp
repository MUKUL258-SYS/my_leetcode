class ThroneInheritance {
public:
set<string>deaths;
// vector<vector<string>>v;
unordered_map<string,vector<string>>mp;
void dfs(string king, vector<string>&res){
    if(!deaths.contains(king))res.push_back(king);
    for(auto nei:mp[king]){
        dfs(nei,res);
    }
}
string k;
    ThroneInheritance(string kingName) {
        //vector<vector<string>>v;
        k=kingName;
    }
   
    void birth(string p, string c) {
        mp[p].push_back(c);
        
    }
    
    void death(string name) {
        deaths.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string>v;
       dfs(k,v);
       return v;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */