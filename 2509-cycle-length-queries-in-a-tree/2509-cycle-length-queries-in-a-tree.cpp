class Solution {
public:
int helper(int a,int  b){
   int cnt = 1;              // the added edge itself
    while(a != b){
        if(a > b) a /= 2;     // move the deeper (larger-valued) node up
        else b /= 2;
        cnt++;
    }
    return cnt;
}
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
       vector<int>res;
        for(auto i:queries){
           int a=i[0];
           int b=i[1];
          res.push_back(helper(a,b));
        }
        return res;
    }
};