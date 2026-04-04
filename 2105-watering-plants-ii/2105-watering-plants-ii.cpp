class Solution {
public:
    int minimumRefill(vector<int>& plants, int cA, int cB) {
        int n=plants.size();
        int i=0;
        int j=n-1;
        int cnt=0;
        int capA=cA;
        int capB=cB;
        while(i<j){
          if(capA<plants[i]){
             capA=cA;
            cnt++;
          }
          if(capB<plants[j]){
            capB=cB;
            cnt++;
          }
          capA-=plants[i];
          capB-=plants[j];
          i++;
          j--;
        }
        if(i==j){
            if(max(capA,capB)<plants[i])cnt++;
        }
        return cnt;
    }
};