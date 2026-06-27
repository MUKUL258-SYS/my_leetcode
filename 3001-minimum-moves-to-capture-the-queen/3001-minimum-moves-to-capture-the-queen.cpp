class Solution {
public:
vector<vector<int>>dirs={{-1,1},{1,1},{1,-1},{-1,-1}};
int e,f;
int a,b;
int c,d;
bool checker(int dir){
  int x=e;
  int y=f;
    while(x>=1 && y>=1 && x<=8 && y<=8){
        if(x==a && y==b)return false;
        if(x==c && y==d)return true;
        x+=dirs[dir][0];
        y+=dirs[dir][1];
    }
    return false;
}
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if(a==e && a==c){
          if(b<d && d<f)return 2;
          if(f<d && d<b)return 2;
            return 1;
        }
        if(b==d && b==f){
           if(a<c && c<e)return 2;
           if(c>e && c<a)return 2;
            return 1;
        }
        this->e=e;
        this->f=f;
        this->a=a;
        this->b=b;
        this->c=c;
        this->d=d;
        for(int k=0;k<4;k++){
            if(checker(k))return 1;
        }
        if(a==e||b==f){
           return 1;

        }
        return 2;
    }
};