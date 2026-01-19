class Solution {
public:
vector<tuple<string,int,int,string>>precomp(vector<string>&t){

    vector<tuple<string,int,int,string>>res;
    for(auto s:t){
        string temp="";
        string s1;
        string s2;
        int n1=-1,n2=-1;
        for(auto i:s){
            if(i==','){
                if(temp.size()&&isdigit(temp[0])){
                  if(n1==-1)n1=stoi(temp);
                  else n2=stoi(temp);
                }
                else{
                    s1=temp;
                }
                temp="";
            }else temp+=i;
        }
        s2=temp;
       // if(n2>1000)continue;
        tuple<string,int,int,string>m=make_tuple(s1,n1,n2,s2);
      //  cout<<s1<<n1<<" "<<n2<<s2<<endl;
        res.push_back(m);
    }
    return res;
}
    vector<string> invalidTransactions(vector<string>& t) {
       vector<tuple<string,int,int,string>>v =precomp(t);
       int n=v.size();
      // return {};
      vector<int>vis(n,0);
       for(int i=0;i<n;i++){

        if(get<2>(v[i])>1000){
            vis[i]=1;
            continue;
        }
        int cnt=0;
         int v1=get<1>(v[i]);
        for(int j=0;j<n;j++){
            if(i==j)continue;
            if((get<0>(v[i])==get<0>(v[j]))&&(get<3>(v[i])!=get<3>(v[j]))){
                int v2=get<1>(v[j]);
                int diff=abs(v2-v1);
                if(diff<=60){
                   // cout<<v1<<" "<<v2<<endl;
                  cnt++;
                  break;
                }
            }
        }
        if(cnt==1)vis[i]=1;
       }
       vector<string>ans;
       for(int i=0;i<n;i++){
        if(vis[i]==1)ans.push_back(t[i]);
       }
       return ans;
       
    }
};