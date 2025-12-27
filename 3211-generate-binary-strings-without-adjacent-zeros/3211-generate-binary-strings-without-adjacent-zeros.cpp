class Solution {
public:
vector<string>v;
void dfs(int i,string temp,int n,int last){
    if(i>=n){
     v.push_back(temp);
        return ;
    }
   temp.push_back('1');
   dfs(i+1,temp,n,1);
   temp.pop_back();
   if(last!=0){
    temp.push_back('0');
    dfs(i+1,temp,n,0);
    temp.pop_back();
   }
}
    vector<string> validStrings(int n) {
        string temp="";
            dfs(0,temp,n,-1);
             return v;
    }
};