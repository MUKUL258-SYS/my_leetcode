class Solution {
public:
int helper(char ch){
    if(ch=='R')return 0;
    else if(ch=='B')return 1;
    return 2;
}
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n=colors.size();
        vector<int>indegree(n,0);
        vector<int>outdegree(n,0);
          for(auto e:edges){
            int u=e[0];
            int v=e[1];
            int c1=helper(colors[u]);
            int c2=helper(colors[v]);
            if(c1==c2)return -1;
            if((c1+1)%3 == c2){
                indegree[v]++;
                outdegree[u]++;
            }
            else{
                outdegree[v]++;
                indegree[u]++;
            }
          }
          int root=-1;
          for(int i=0;i<n;i++){
            if(outdegree[i]>2)return -1;
            if(indegree[i]==0){
                if(root!=-1)return -1;
                root=i;
            }
            else if(indegree[i]==2)return -1;
          }
          return root;
    }
};