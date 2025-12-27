class Solution {
public:
vector<string>v;
void dfs(int i,string temp,int n,int last){
    if(i>=n){
     v.push_back(temp);
        return ;
    }
    if(last==-1){
           //temp+='0';
           dfs(i+1,temp+'0',n,0);
          dfs(i+1,temp+'1',n,1);
    }
    else if(last==0){
        dfs(i+1,temp+'1',n,1);
    }
    else{
        dfs(i+1,temp+'1',n,1);
        dfs(i+1,temp+'0',n,0);
    }
}
    vector<string> validStrings(int n) {
        string temp="";
            dfs(0,temp,n,-1);
             return v;
    }
};