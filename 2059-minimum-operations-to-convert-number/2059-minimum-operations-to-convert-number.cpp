class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue<int>q;
        q.push(start);
        vector<int>vis(1001,false);
       int steps=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
            int f=q.front();
            q.pop();
            if(f==goal)return steps;
            if(f<0||f>1000||vis[f])continue;
            vis[f]=true;
            for(auto j:nums){
                int v1=j+f;
                int v2=f-j;
                int v3=j^f;
                q.push(v1);
                q.push(v2);
                q.push(v3);
            }
        }
            steps++;
            
        }
        return -1;
        
    }
};