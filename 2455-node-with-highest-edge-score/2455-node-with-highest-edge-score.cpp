class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n=edges.size();
        vector<long long>vp(n,0);
        for(int i=0;i<n;i++){
            vp[edges[i]]+=i;
        }
        for(auto i:vp)cout<<i<<endl;
        long long maxi=0;
        long long idx=-1;
        for(int i=0;i<n;i++){
            if(vp[i]>maxi){
                idx=i;
                maxi=vp[i];
            }
        }
        return idx;
    }
};