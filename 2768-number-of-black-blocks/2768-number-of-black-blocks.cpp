class Solution {
public:
set<pair<int,int>>s,vis;
int n,m;
bool isValid(int x,int y){
    if(x>=0 && x<m && y>=0 && y<n && !vis.contains({x,y}))return true;

    return false;
    
}
vector<vector<int>>dirs={{-1,-1},{1,1},{-1,1},{1,-1}};
long long helper(int x,int y,int dir){
    int nx=x+dirs[dir][0];
    int ny=y+dirs[dir][1];
   // cout<<nx<<" "<<ny<<endl;
    if(!isValid(nx,ny) || !isValid(nx,y) || !isValid(x,ny))return -1;
    long long cnt=0;
    if(s.contains({nx,ny})){
       cnt++;
    }
     if(s.contains({nx,y})){
        cnt++;
    }
     if(s.contains({x,ny})){
        cnt++;
    }
    return cnt;
}
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& c) {
        vector<long long>res(5,0);
       this->m=m;
       this->n=n;
    //    unordered_set<pair<int,int>>s,vis;
        for(auto i:c){
             s.insert({i[0],i[1]});
        }
        sort(c.begin(),c.end());
        long long  total=1ll*(m-1)*(n-1);
       long long cnt=0;
        for(auto i:c){
            int x=i[0];
            int y=i[1];
            for(int k=0;k<4;k++){
              //  cnt++;
                int value=helper(x,y,k);
               // cout<<value<<endl;
                if(value>-1){res[value+1]++;
                    cnt++;
                }
              //  res[value]++;
            }
            vis.insert({x,y});
        }
        //for(int i=1;i<5;i++)cnt+=res[i];
         res[0]=total-cnt;
         return res;
    }
};