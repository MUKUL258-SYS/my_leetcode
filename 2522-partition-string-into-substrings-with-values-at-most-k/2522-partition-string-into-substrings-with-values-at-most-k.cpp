class Solution {
public:
    int minimumPartition(string s, int k) {
        int cnt=1;
        long long val=0;
        for(auto ch:s){
            int digit=ch-'0';
            if(digit>k)return -1;
            if(val*10+digit<=k){
                 val=val*10+digit;
            }
            else{
                val=digit;
                cnt++;
            }
        }
        return cnt;
    }
};