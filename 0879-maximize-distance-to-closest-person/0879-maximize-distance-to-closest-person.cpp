class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        int cnt=0;
        int ans=1;
        int cnt_zeros=0;
        for(int i=0;i<n;i++){
           if(seats[i]==0){
            cnt++;
           }
           else{
             
            if(cnt_zeros>=1)ans=max(ans,(cnt+1)/2);
            else ans=max(ans,cnt);
            cnt=0;
            cnt_zeros++;
           }
        }
         ans=max(ans,cnt);
         return ans;
    }
};