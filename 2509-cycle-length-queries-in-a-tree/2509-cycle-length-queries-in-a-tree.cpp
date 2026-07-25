class Solution {
public:
int helper(int a,int  b){
 int cnt=1;
 while(a!=b){
    cnt++;
    if(a>b){
        //cnt++;
        a/=2;
    }
    else{
    b/=2;
    }
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