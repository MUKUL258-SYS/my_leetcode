class Robot {
public:
int n,m;
vector<vector<int>>vp;
int p;
int sz;
bool moved;
    Robot(int width, int height) {
        p=0;
        moved=false;
        n=height;
        m=width;
       // sz=2*(height+width);
        //vp.resize(width*height);
        for(int j=0;j<m;j++){
            vp.push_back({0,j,0});
        }
        for(int i=1;i<n;i++){
            vp.push_back({i,m-1,1});
        }
        for(int i=m-2;i>=0;i--){
            vp.push_back({n-1,i,2});
        }
        for(int i=n-2;i>0;i--){
            vp.push_back({i,0,3});
        }
        for(auto i:vp){
            for(auto j:i){
                cout<<j<<" ";
            }
            cout<<endl;

        }
        sz=vp.size();
        
    }
    
    void step(int num) {
        if(num>0)moved=true;
        num=num%sz;
       
        p=(p+num)%sz;

    }
    
    vector<int> getPos() {
        return {vp[p][1],vp[p][0]};
    }
    
    string getDir() {
        if(p==0&&moved==true)return "South";
        int v=vp[p][2];
        if(v==0)return "East";
        else if(v==1)return "North";
        else if(v==2)return "West";
        else return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */