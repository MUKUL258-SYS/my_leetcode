class Solution {
public:
vector<int>v;
void dfs(int n,int k,string str){
    if(n<0)return ;
    if(n==0){
        v.push_back(stoi(str));
        return ;
    }
    int prev=str.back()-'0';
    if(prev-k>=0){
        char value=(prev-k)+'0';
        dfs(n-1,k,str+value);
    }
    if(prev+k<=9){
        char value=(prev+k)+'0';
        dfs(n-1,k,str+value);
    }

}
    vector<int> numsSameConsecDiff(int n, int k) {
        if(k==0){
           // int n2=n;
            for(char i='1';i<='9';i++){
                int n2=n;
                string s="";
                while(n2--){
                s+=i;
                }
                v.push_back(stoi(s));
            }
            return v;
        }
     for(int i=1;i<=9;i++){
        string str="";
        str+=to_string(i);
        //dfs(n,k,str,i);
        dfs(n-1,k,str);
     }
     
     //dfs(n-1,k,"7");
     return v;
    }
};