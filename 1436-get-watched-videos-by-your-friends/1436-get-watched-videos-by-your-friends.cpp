class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>&arr, vector<vector<int>>& friends, int id, int level) {
        int n=arr.size();
        vector<int>vis(n,false);
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<friends[i].size();j++)
                adj[i].push_back(friends[i][j]);
        }
        queue<int>q;
        q.push(id);
        int l=0;
        vis[id]=true;
        while(!q.empty()){
        if(l==level)break;
          int sz=q.size();
          while(sz--){
            int node=q.front();
            q.pop();
            for(auto nei:adj[node]){
                if(!vis[nei]){
                    q.push(nei);
                    vis[nei]=true;
                }
            }
          }
           l++;
        }
        unordered_map<string,int>mp;
      //  priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>>pq;

      /*  while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto &s:arr[node]){
                //pq.push({node,s});
                mp[s]++;
            }
        }
        */
         unordered_map<string,int> freq;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto& s : arr[node]) {
                freq[s]++;
            }
        }

        // ✅ Use min-heap to sort by freq and then lex
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> pq;
        for (auto& [video, count] : freq) {
            pq.push({count, video});
        }

        vector<string>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;

        }
    
};