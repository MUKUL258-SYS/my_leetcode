class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<bool>rows(n,false);
        vector<bool>cols(m,false);
        for(auto i:indices){
            int row=i[0];
            int col=i[1];
            rows[row]=rows[row]^true;
            cols[col]=cols[col]^true;
        }
        int r=0;
        int c=0;
        for(int i=0;i<n;i++)if(rows[i])r++;
        for(int i=0;i<m;i++)if(cols[i])c++;
        return r*m+c*n-(2*r*c);

    }
};