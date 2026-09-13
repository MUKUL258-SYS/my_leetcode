class Solution {
public:
    int minBishopMoves(vector<int>& s, vector<int>& t) {
      int x=s[0];
      int y=s[1];
      if(abs(x-t[0]) == abs(y-t[1]))return 1;
      int nx=x;
      int ny=y;

      while(nx>=1 && ny>=1){
         if(abs(nx-t[0]) == abs(ny-t[1]))return 2;
        nx-=1;
        ny-=1;
        // if(abs(nx-t[0]) == abs(ny-t[1]))return 2;
      }
        nx=x;
       ny=y;

      while(nx<=8 && ny<=8){
        if(abs(nx-t[0]) == abs(ny-t[1]))return 2;
        nx+=1;
        ny+=1;
        // if(abs(nx-t[0]) == abs(ny-t[1]))return 2;
      }
       nx=x;
       ny=y;

      while(nx<=8 && ny>=1){
        if(abs(nx-t[0]) == abs(ny-t[1]))return 2;
        nx+=1;
        ny-=1;
        // if(abs(nx-t[0]) == abs(ny-t[1]))return 2;
      }
      nx=x;
       ny=y;

      while(nx>=1 && ny<=8){
        if(abs(nx-t[0]) == abs(ny-t[1]))return 2;
        nx-=1;
        ny+=1;
        // if(abs(nx-t[0]) == abs(ny-t[1]))return 2;
      }
      return -1;
    
    }
};