class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int>v(3000,0);
      for(auto i:logs){
        v[i[0]]++;
        v[i[1]]--;
      }
      for(int i=1951;i<=2050;i++){
             v[i]+=v[i-1];
      }
      int mini_year=2050;
      int maxi=-1;
      for(int i=1950;i<=2050;i++){
        if(v[i]>maxi){
            mini_year=i;
            maxi=v[i];
        }
      }
      return mini_year;
    }
};