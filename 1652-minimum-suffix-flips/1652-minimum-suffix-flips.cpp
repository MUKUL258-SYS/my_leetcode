class Solution {
public:
    int minFlips(string target) {
        int i=target.find('1');
        if(i==-1)return 0;
        int n=target.size();
        char ok='0';
        int cnt=0;
        while(i<n){
         if(target[i]!=ok){
            ok=target[i];
            cnt++;
         }
         i++;
        }
        return cnt;
    }
};