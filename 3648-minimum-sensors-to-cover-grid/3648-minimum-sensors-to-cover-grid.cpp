class Solution {
public:
    int minSensors(int n, int m, int k) {
       double side=2*k+1;
       int l=ceil(n/side);
       int w=ceil(m/side);
       return l*w; 
    }
};