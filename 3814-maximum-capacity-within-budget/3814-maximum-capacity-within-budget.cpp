class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n=costs.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
           //v.push_back({capacity[i],costs[i]});
           v.push_back({costs[i],capacity[i]});
        }
        sort(v.begin(),v.end());
        int i=0;
        int j=n-1;
        int ans=0;
        for(int i=0;i<n;i++){
            if(costs[i]<budget)ans=max(ans,capacity[i]);
        }
        
        vector<int>pre(n);
        pre[0]=v[0].second;
        for(int i=1;i<n;i++){
            pre[i]=max(pre[i-1],v[i].second);
        }

        for(int i=1;i<n;i++){
            int c=v[i].first;
            if(c>=budget)break;
            int rem=budget-c;
            int l=0;
            int r=i-1;
            int idx=-1;
            while(l<=r){
                int mid=(l+r)/2;
                if(v[mid].first>=rem){
                   r=mid-1;
                }
                else{
                    idx=mid;
                    l=mid+1;
                }
                
            }
            if(idx!=-1){
               ans=max(ans,pre[idx]+v[i].second);
            }
        }
        return ans;

    }
};