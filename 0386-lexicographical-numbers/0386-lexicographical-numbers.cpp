class Solution {
public:
vector<int>res;
int n;
void dfs(long long current){
    if(current>n)return ;
     res.push_back(current);
   for(int i=0;i<=9;i++){
    int temp=current*10+i;
    if(temp>n)break;
   // res.push_back(temp);
    dfs(temp);
   }
}
    vector<int> lexicalOrder(int n) {
        this->n=n;
        for(int i=1;i<=min(n,9);i++){
                dfs(i);
        }
        return res;
    }
};