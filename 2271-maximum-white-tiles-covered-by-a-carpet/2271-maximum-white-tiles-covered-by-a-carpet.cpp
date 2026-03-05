class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int Len) {
        int i=0,j=0,ans=0,cover=0,n=tiles.size(),p;
        sort(tiles.begin(),tiles.end());
        for(i=0;i<n&&ans<Len; ){
            if(tiles[j][0]+Len>tiles[i][1]){
            cover+=(tiles[i][1]-tiles[i][0]+1);
            ans=max(ans,cover);
             i++;
            }
            else{
                p=max(tiles[j][0]+Len-tiles[i][0],0);
                ans=max(ans,cover+p);
                cover-=(tiles[j][1]-tiles[j][0]+1);
                j++;

            }
            
        }
        return ans;
    }
};