class Solution {
public:
vector<int>v;
vector<int>ans;
int mini,n;
void dfs(int k,int idx,long long product,vector<int>&temp){
    if(product>n)return ;
    if(k==0){
        if(product==n){
        sort(temp.begin(),temp.end());
       // for(auto i:temp)cout<<i<<" ";
        cout<<endl;
        int v=temp.back()-temp[0];
        //mini=min(mini,v);
        if(v<mini){
            mini=v;
            ans=temp;
        }
        }
        return ;
    }
    for(int i=idx;i<v.size();i++){
        temp.push_back(v[i]);
        
        dfs(k-1,i,product*v[i],temp);

        temp.pop_back();
    }
    
}

    vector<int> minDifference(int n, int k) {
        mini=INT_MAX;
        vector<int>temp;
        this->n=n;
        for(int i=1;i*i<=n;i++){
            if((n%i)==0){
                v.push_back(i);
                v.push_back(n/i);
            }
        }

        sort(v.begin(),v.end());
        //for(auto i:v)cout<<i<<endl;
        long long p=1;
        dfs(k,0,p,temp);
        return ans;
    }
};