class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
      int sum=0;
      int cnt=0;
      for(auto i:moves){
        if(i=='_'){
            cnt++;
            continue;
        }
        sum+=(i=='R'?1:-1);
      }
      return abs(sum)+cnt;

    }
};