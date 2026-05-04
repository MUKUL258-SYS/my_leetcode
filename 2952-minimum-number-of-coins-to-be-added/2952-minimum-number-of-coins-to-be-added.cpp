class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int maxi=0;
        sort(coins.begin(),coins.end());
        int cnt=0;
        for(auto i:coins){
            while(maxi<target&&(maxi+1<i)){
              maxi+=(maxi+1);
              cnt++;
            }
            if(maxi>=target){
                break;
            }
            maxi+=(i);

        }
        while(maxi<target){
            maxi+=(maxi+1);
            cnt++;
        }
        return cnt;
        
    }
};