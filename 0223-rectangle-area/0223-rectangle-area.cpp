class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int a=max(ax1,bx1);
        int b=min(ax2,bx2);
        int c=min(ay2,by2);
        int d=max(ay1,by1);
        int d1=max(0,b-a);
        int d2=max(0,c-d);
        int ar2=d1*d2;
        int ar1=max(0,ax2-ax1)*max(0,ay2-ay1)+max(0,bx2-bx1)*max(0,by2-by1);
        return ar1-ar2;
    }
};