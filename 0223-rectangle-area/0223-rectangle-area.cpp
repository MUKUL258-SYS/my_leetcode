class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int len1=abs(bx2-bx1);
        int width1=abs(by1-by2);
        int len2=abs(ax2-ax1);
        int width2=abs(ay2-ay1);
        int res=(len1*width1)+(len2*width2);
        int maxix=max(ax1,bx1);
        int maxiy=max(ay1,by1);
        int minix=min(ax2,bx2);
        int miniy=min(ay2,by2);
       // int value=((maxix-minix) * abs(maxiy-miniy));
       int x=minix-maxix;
       int y=miniy-maxiy;
       if(x<=0||y<=0)return res;
        return res-(x*y);
    }
};