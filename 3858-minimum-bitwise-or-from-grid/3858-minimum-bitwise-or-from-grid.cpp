class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
       int ans=(1<<20)-1;
       for(int bit=19;bit>=0;bit--){
        int temp=ans^(1<<bit);
        bool f=true;
        for(auto &row:grid){
            bool m=false;
            for(auto &v:row){
                if((temp|v)==temp){
                    m=true;
                    break;
                }
            }
            if(!m){
                f=false;
                break;
            }
        }
        if(!f)continue;
        ans=temp;
       }
       return ans; 
    }
};