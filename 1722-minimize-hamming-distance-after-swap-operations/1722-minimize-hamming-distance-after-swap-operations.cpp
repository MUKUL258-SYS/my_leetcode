class Solution {
public:
vector<vector<int>>adj;
void  dfs(vector<int>&parent,int node,vector<bool>&vis){
 //   if(parent[node]==node)return node;
if(vis[node])return ;
  vis[node]=true;
    for(auto nei:adj[node]){
        if(vis[nei]==false){
            parent[nei]=min(parent[nei],parent[node]);
            dfs(parent,nei,vis);
        }
    }
 }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& a) {
        for(auto &i:a){
            if(i[0]>i[1]){
                swap(i[0],i[1]);
            }
        }
    int n=source.size();
    adj.resize(n);
    for(auto i:a){
        int src=i[0];
        int dest=i[1];
    adj[src].push_back(dest);
    adj[dest].push_back(src);
    }
    vector<int>parent(n);
    vector<bool>vis(n,false);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    for(int i=0;i<n;i++){
        if(vis[i]==false){
            dfs(parent,i,vis);
        }
    }
    /*for(int i=0;i<n;i++){
        cout<<i<<" "<<parent[i]<<endl;
    }*/
/*unordered_map<int,int>mp,mp2;
for(int i=0;i<n;i++){
    mp[source[i]]=i;
}
for(int i=0;i<n;i++){
    mp2[target[i]]=i;
    }
int cnt=0;
for(int i=0;i<n;i++){
    if(mp.find(target[i])==mp.end()){
        cnt++;
        continue;
    }
     /*if(mp2.find(source[i])==mp2.end()){
        cnt++;
        continue;
    }


    if(source[i]!=target[i]){
        int idx=mp[target[i]];
        if(parent[i]!=parent[idx])cnt++;
    }
}


    return cnt;
    */
     int ans = 0;

        // group indices by component
        unordered_map<int, vector<int>> groups;

        for (int i = 0; i < n; i++) {
            groups[parent[i]].push_back(i);
        }

        // process each component separately
        for (auto &g : groups) {

            unordered_map<int, int> freq;

            // count source frequencies
            for (int idx : g.second) {
                freq[source[idx]]++;
            }

            // match target values
            for (int idx : g.second) {

                if (freq[target[idx]] > 0) {
                    freq[target[idx]]--;
                } else {
                    ans++;
                }
            }
        }

        return ans;
            
    }
};