class Solution {
public:
    vector<int> constructRectangle(int area) {
        
        int n=area;
        vector<int>v;
        for(int i=1;i*i<=n;i++){
               if(n%i)continue;
               int a=i;
               int b=n/i;
            v={b,a};
        }
        return v;
    }
};