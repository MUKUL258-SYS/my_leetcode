class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        map<int,int>m;
        int ans=0;
        for(auto i:rolls){
            if(m.size()==k){
                ans++;
                m.clear();
            }
                m[i]++;
            
        }
        if(m.size()==k){
                ans++;
           }
        return ans+1;
    }
};