class Solution {
public:
unordered_map<int,int>mp;
bool helper(int n){
    int m=n;
    int diff=0;
    while(m){
        int rem=m%10;
        if(mp[rem]<0)return false;
        if(mp[rem]!=rem)diff++;
        m/=10;
    }
    return diff>0;
}
    int rotatedDigits(int n) {
        mp[1]=1;
        mp[2]=5;
        mp[3]=-1;
        mp[4]=-1;
        mp[5]=2;
        mp[6]=9;
        mp[7]=-1;
        mp[8]=8;
        mp[9]=6;
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(helper(i)){
                cout<<i<<endl;
                cnt++;
            }
        }
        return cnt;
    }
};