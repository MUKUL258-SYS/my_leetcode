class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int>vp;
        for(int i=0;i<(1<<n);i++){
            vp.push_back(i^(i>>1));
        }
        //return vp;
        vector<int>res;
        map<int,int>m;
        n=vp.size();
        for(int i=0;i<n;i++)m[vp[i]]=i;
        int s=m[start];
        for(int i=s;i<n;i++)res.push_back(vp[i]);
        for(int i=0;i<s;i++)res.push_back(vp[i]);
        return res;
        
        //return vp;
    }
};