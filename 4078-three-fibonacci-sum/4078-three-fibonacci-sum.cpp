class Solution {
public:
    bool threeFibonacciSum(int n) {
        vector<int>v;
        
        int n1=0;
        int n2=1;
        v.push_back(n1);
        while(n1+n2 <= n){
        v.push_back(n2);
        int s=n1+n2;
        n1=n2;
        n2=s;    
        }
        for(int i=1;i+1<v.size();i++){
            if(v[i]+v[i-1]+v[i+1] == n)return true;
        }
        return false;
    }
};