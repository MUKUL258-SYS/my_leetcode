class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();
        int ans=0;
        int cnt=1;
        for(int i=1;i<n+k-1;i++){
           if(colors[i%n]==colors[(i-1)%n]){
              cnt=1;
           }
           else{
              //cnt=1;
              cnt++;
           }
           if(cnt>=k){
            ans++;
           }
        }
        return ans;
    }
};