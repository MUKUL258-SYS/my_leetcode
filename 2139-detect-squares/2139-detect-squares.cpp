class DetectSquares {
public:
//vector<pair<int,int>>v;
map<pair<int,int>,int>mp;
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
 mp[{point[0],point[1]}]++;       
    }
    
    int count(vector<int> point) {
       int y2=point[1];
       int x2=point[0];
         pair<int,int>p1,p2,p3,p4;
         long long ans=0;
       for(auto i:mp){
           if(i.first.first==x2){
              int d=abs(i.first.second-y2);
              if(d==0)continue;
             int x1=i.first.first;
             int y1=i.first.second;
       p1={x1-d,y1};
       p2={x2-d,y2};
       p3={x1+d,y1};
       p4={x2+d,y2};
         ans+=(1LL*mp[p1]*mp[p2]*i.second);
       ans+=(1LL*mp[p3]*mp[p4]*i.second);
           }
       }
    /*   int x3,x4,y3,y4;

       pair<int,int>p1,p2,p3,p4,p5,p6,p7,p8;
       p1={x1-d,y1};
       p2={x2-d,y2};
       p3={x1+d,y1};
       p4={x2+d,y2};
      // p5={x1-d,y2};
      // p6={x2-d,y1};
      // p7={x1+d,y2};
      // p8={x2+d,y1};

       long long ans=0;
       ans+=(mp[p1]*mp[p2]*mp[{x1,y1}]);
       ans+=(mp[p3]*mp[p4]*mp[{x1,y1}]);
      // ans+=(mp[p5]*mp[p6]*mp[{x1,y1}]);
      // ans+=(mp[p7]*mp[p8]*mp[{x1,y1}]);
       return ans;
       */
       return ans;

    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */