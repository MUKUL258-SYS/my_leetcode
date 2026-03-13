class CombinationIterator {
public:
int n;
queue<string>q;
int len;
void dfs(int j,string s,string temp){
    int n=s.size();
    if(j>=n||temp.size()==len){
    if(temp.size()==len){q.push(temp);
        // cout<<temp<<endl;
    }
        
        return ;
    }
    
    for(int i=j;i<n;i++){
         temp.push_back(s[i]);
         dfs(i+1,s,temp);
         temp.pop_back();
    }
}
    CombinationIterator(string characters, int combinationLength){
        len=combinationLength;
         dfs(0,characters,"");
    }
    
    string next() {
        string ans="";
        if(q.size()){
            ans=q.front();
            q.pop();
        }
        return ans;
    }
    
    bool hasNext() {
        return q.size()>0;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */