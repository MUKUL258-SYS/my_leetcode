class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double dp[104][104]={0.0};
        dp[0][0]=(double)poured;
        int row=query_row;
        int col=query_glass;
        for(int r=0;r<=row;r++){
            for(int c=0;c<=col;c++){
                if(dp[r][c]>1){
                    double v=dp[r][c];
                    double extra=(v-1)/2.0;
                    dp[r][c]=1;
                    dp[r+1][c]+=extra;
                    dp[r+1][c+1]+=extra;
                }
            }
        }
        return dp[row][col];

    }
};