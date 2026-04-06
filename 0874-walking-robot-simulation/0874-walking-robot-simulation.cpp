class Solution {
public:
struct pair_hash {
        size_t operator()(const pair<int,int>& p) const {
            return ((long long)p.first << 32) ^ (p.second);
        }
    };
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<pair<int,int>,pair_hash>s;
        for(auto i:obstacles)s.insert({i[0],i[1]});
        vector<pair<int,int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
        int d=0;
        int x=0;
        int y=0;
        int ans=0;
        for(auto c:commands){
            if(c==-1){
                d=(d+1)%4;
            }
            else if(c==-2){
                d=(d+3)%4;
            }
            else{
                for(int j=0;j<c;j++){
                    int nx=x+dir[d].first;
                    int ny=y+dir[d].second;
                    if(s.count({nx,ny})){
                        break;
                    }
                    x=nx;
                    y=ny;
                    ans=max(ans,x*x+y*y);
                }
            }
        }
        return ans;
    }
};