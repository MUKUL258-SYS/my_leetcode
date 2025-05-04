class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
        int ans=INT_MAX;
        for(int i=1;i<=6;i++){
            bool flag=true;
            int cnt=0;
            for(int j=0;j<n;j++){
               if(tops[j]!=i&&bottoms[j]!=i){
                flag=false;
                break;
            }
            if(tops[j]!=i)cnt++;
          }
          if(flag)ans=min(ans,cnt);
            flag=true;
             cnt=0;
            for(int j=0;j<n;j++){
               if(tops[j]!=i&&bottoms[j]!=i){
                flag=false;
                break;
            }
            if(bottoms[j]!=i)cnt++;
          }
          if(flag)ans=min(ans,cnt);
        }
        return ans==INT_MAX?-1:ans;
    }
};