class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
         // int n=edges.size();
        vector<unordered_set<int>>adj(n+1);
        vector<int>degree(n+1,0);
        //int n=edges.size();
       for(auto i:edges){
         adj[i[0]].insert(i[1]);
         adj[i[1]].insert(i[0]);
         degree[i[0]]++;
         degree[i[1]]++;
       }
      /* for(int i=0;i<n;i++){
        for(int j=0;j<adj[i].size();j++){
            for(int k=0;k<adj[j].size();k++){
                if()
            }
        }
       }*/
       int mini=INT_MAX;
       for(int i=0;i<=n;i++){
       //unordered_set<int>s1=adj[i];
       //if(s1.size()==0)continue;
      // if(j<=i)continue;
        for(auto j:adj[i]){
            if(j<=i)continue;
         // unordered_set<int>s2=adj[j];
          //if(s2.size()==0)continue;
         // if(k<=j)continue;
            for(int k:adj[j]){
                 if(k<=j)continue;
                if(adj[k].contains(i)){
                mini=min(mini,degree[i]+degree[j]+degree[k]-6);

                }
            }
        }

       }
       return mini==INT_MAX?-1:mini;

    }
};