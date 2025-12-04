class Solution {
public:
long long helper(long long n){
    return (n)*(n+1)/2;
}
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        long long s=helper(n);
        vector<int>v;
        if(target>s||target<-s)return {};
        for(int i=n;i>=1;i--){

           if((helper(i-1)-i)>=target){
            target+=i;
            v.push_back(-1*i);
           }
           else{
            target-=i;
            v.push_back(i);
           }
        }
        if(target!=0)return {};
        sort(v.begin(),v.end());
        return v;
        
    }
};