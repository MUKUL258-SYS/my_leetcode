class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int n=drones.size();
        int k=0;
        int ans=-1;
        int mini=INT_MAX;
        for(auto i:drones){
          int d1=abs(i[0]-target[0]);
          int d2=abs(i[1]-target[1]);
          if(d1+d2 <= i[2] && d1+d2<mini){
              ans=k;
              mini=d1+d2;
          }
          k++;
        }
        return ans;
    }
};