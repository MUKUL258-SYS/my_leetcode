class Solution {
public:
bool seive(int n){
   if(n==0||n==1)return false;
    for(int i=2;i*i<=n;i++){
      if(n%i==0)return false;
    }
    return true;
}
    bool completePrime(int num) {
        string str=to_string(num);
        int n=str.size();
        for(int i=1;i<=n;i++){
            string s=str.substr(0,i);
            if(!seive(stoi(s)))return false;
        }
        int j=n-1;
        for(int i=1;i<=n;i++){
            string s=str.substr(j,i);
             if(!seive(stoi(s)))return false;
             j--;
        }
        return true;
    }
};