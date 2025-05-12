class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int sr=0;
        int sc=0;
        int er=n-1;
        int ec=n-1;
        vector<vector<int>>v(n,vector<int>(n,0));
        int maxi=n*n;
        int cnt=1;
        while(cnt<=maxi){
            if(sr>er||sc>ec)break;
            for(int i=sc;i<=ec;i++){
                v[sr][i]=cnt++;
                if(cnt>maxi)break;
            }
            sr++;
             if(sr>er||sc>ec)break;
            for(int i=sr;i<=er;i++){
                v[i][ec]=cnt++;
                 if(cnt>maxi)break;
            }
            ec--;
             if(sr>er||sc>ec)break;
            for(int i=ec;i>=sc;i--){
                v[er][i]=cnt++;
                 if(cnt>maxi)break;
            }
            er--;
             if(sr>er||sc>ec)break;
            for(int i=er;i>=sr;i--){
                v[i][sc]=cnt++;
                if(cnt>maxi)break;
            }
            sc++;
             if(sr>er||sc>ec)break;
        }
        return v;
    }
};