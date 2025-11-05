class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
       // vector<vector<int>>adj(n);
        vector<int>v(n,0);
        for(auto i:edges){
            v[i[1]]++;
        }
        vector<int>res;
        for(int i=0;i<v.size();i++){
            if(v[i]==0)res.push_back(i);
        }
        if(res.size()>1)return -1;
        return res[0];
    }
};