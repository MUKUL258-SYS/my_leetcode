class Solution {
public:
int find(vector<int>&parent,int i){
    if(parent[i]==i)return i;
    return parent[i]=find(parent,parent[i]);
}
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
    int n=vals.size();
    int m=edges.size();
    int ans=0;
    vector<int>parent(n);
    vector<vector<int>>x(n);
    for(int i=0;i<n;i++){
        parent[i]=i;
        x[i]={vals[i],1};
    }
    sort(edges.begin(),edges.end(),[&](vector<int>&a,vector<int>&b){
        return max(vals[a[0]],vals[a[1]])<max(vals[b[0]],vals[b[1]]);
    });
    for(int i=0;i<m;i++){
        int a=find(parent,edges[i][0]);
        int b=find(parent,edges[i][1]);
        if(x[a][0]==x[b][0]){
            parent[a]=b;
            ans+=x[a][1]*x[b][1];
            x[b][1]+=x[a][1];
        }else{
            if(x[a][0]>x[b][0])parent[b]=a;
            else parent[a]=b;
        }
    }
    return ans+n;
    }
};