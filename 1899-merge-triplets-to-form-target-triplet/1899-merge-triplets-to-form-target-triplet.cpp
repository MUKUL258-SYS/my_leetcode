class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& t, vector<int>& target) {
       int n=t.size();
       vector<int>v={0,0,0};
       // vector<int>v(n,true);
        for(auto i:t){
            if(i==target)return true;
        }
        for(int i=0;i<n;i++){
            if(t[i][0]>target[0]||t[i][1]>target[1]||t[i][2]>target[2]){
            //    v[i]=false;
                continue;
            }
            v[0]=max(v[0],t[i][0]);
            v[1]=max(v[1],t[i][1]);
            v[2]=max(v[2],t[i][2]);

            
        }
        return v==target;
    }
};