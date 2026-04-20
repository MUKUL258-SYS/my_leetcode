class Solution {
public:
vector<vector<int>>adj1;
vector<vector<int>>adj2;
int bfs(vector<vector<int>>&adj,int node,int k){
    queue<int>q;
    q.push(node);
    int l=0;
    unordered_set<int>vis;
    vis.insert(node);
    while(!q.empty()){
         int sz=q.size();
         if(l>=k)break;
         while(sz--){
             auto f=q.front();
             q.pop();
             for(auto nei:adj[f]){
              
               if(vis.count(nei))continue;
               vis.insert(nei);
               q.push(nei);
               
             }

         }
         l++;
    }
    return vis.size();
}
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n=edges1.size()+1;
        int m=edges2.size()+1;
        if(k==0){
            vector<int>res;
            for(int i=0;i<n;i++)res.push_back(1);
            return res;
        }
        adj1.resize(n+1);
        adj2.resize(m+1);
       // this->k=k;
        for(auto i:edges1){
            adj1[i[0]].push_back(i[1]);
            adj1[i[1]].push_back(i[0]);
        }
        for(auto i:edges2){
            adj2[i[0]].push_back(i[1]);
            adj2[i[1]].push_back(i[0]);
        }
        vector<int>v1,v2;
        for(int i=0;i<n;i++){
        v1.push_back(bfs(adj1,i,k));
        }
        for(int i=0;i<m;i++){
        v2.push_back(bfs(adj2,i,k-1));
        }
        for(auto i:v1)cout<<i<<" ";
        cout<<endl;
        for(auto i:v2)cout<<i<<" ";
        //n=v1.size();
        //m=v2.size();
        vector<int>res;
        for(int i=0;i<n;i++){
            int maxi=0;
            for(int j=0;j<m;j++){
                maxi=max(maxi,v1[i]+v2[j]);
            }
            res.push_back(maxi);
        }
        return res;



    }
};