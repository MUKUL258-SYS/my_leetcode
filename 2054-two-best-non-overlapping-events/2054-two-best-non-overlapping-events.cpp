class Solution {
public:
using pi=pair<int,int>;
    int maxTwoEvents(vector<vector<int>>& e) {
        sort(e.begin(),e.end());
        priority_queue<pi,vector<pi>,greater<>>pq;
        int maxi=0;
        int ans=0;
        for(auto i:e){
            int s=i[0];
            int e=i[1];
            int val=i[2];
            while(!pq.empty()&&pq.top().first<s){
                maxi=max(maxi,pq.top().second);
                pq.pop();

            }
            ans=max(ans,maxi+val);
            pq.push({e,val});
        }
        return ans;
    }
};