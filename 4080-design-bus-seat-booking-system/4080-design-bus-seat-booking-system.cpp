class BusBooking {
public:
vector<vector<int>>v;
int tt;
int min_time;
    BusBooking(int n) {
        v.resize(n,vector<int>(4,0));
        tt=0;
        min_time=0;
    }
    
    void toggle(string seat) {
        int col=seat[0]-'A';
        int row=stoi(seat.substr(1));
        row--;
        if(v[row][col]==0){
            // v[row][col]++;
            int t=0;
              if(col==0 ||col==3){
                if((col-1>=0 && v[row][col-1]==1) ||(col+1<4 && v[row][col+1]==1)){
                    t+=3;
                }
                else{
                    t+=1;
                }
             }
             else{
                t+=1;
             }
             tt+=t;
             v[row][col]=t;
             min_time++;
        }
        else{
              tt-=v[row][col];
              v[row][col]=0;
             min_time--;
        }
    }
    
    int getTotalTime() {
        return tt;
    }
    
    int getMinTime() {
        return min_time;
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */