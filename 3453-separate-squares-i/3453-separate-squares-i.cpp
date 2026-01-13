/*class Solution {
public:
vector<vector<int>>s;
double calculatearea(double midy){
      double area=0;
      for(auto j:s){
        double ylow=j[1];
        double len=j[2];
        double ytop=ylow+len;
        if(ylow>=midy)continue;
        if(ytop<=midy){
            area+=(1.0*len*len);
        }
        else{
            area+=1.0*len*(midy-ylow);
        }
      }
      return area;
}
    double separateSquares(vector<vector<int>>& squares) {
     double totalarea=0;
        s=squares;
        //int low=0;
        //int hight=2e9;
        double low=2e9;
        double high=0;
        for(auto i:squares){
             totalarea+=(1.0*i[2]*i[2]);
             double y=i[1];
             double l=i[2];
           low=min(low,y);
           high=max(high,y+l);
        }
        double halfarea=totalarea/2.0;
        double maxi=1e-5;
        while((high-low)>maxi){
            double mid=(high-low)/2.0+low;
            if(calculatearea(mid)>=halfarea){
                high=mid;
            }
            else low =mid;
        }
        return high;
    }
};
*/
class Solution {
public:
vector<vector<int>>s;
double calculatearea(double midy){
      double area=0;
      for(auto& j:s){
        double ylow=j[1];
        double len=j[2];
        double ytop=ylow+len;
        if(ylow>=midy)continue;
        if(ytop<=midy){
            area+=(1.0*len*len);
        }
        else{
            area+=1.0*len*(midy-ylow);
        }
      }
      return area;
}
    double separateSquares(vector<vector<int>>& squares) {
     double totalarea=0;
        s=squares;
        //int low=0;
        //int hight=2e9;
        double low=1e18;
        double high=-1e18;
        for(auto& i:squares){
             totalarea+=(1.0*i[2]*i[2]);
             double y=i[1];
             double l=i[2];
           low=min(low,y);
           high=max(high,y+l);
        }
        double halfarea=totalarea/2.0;
        for(int i=0;i<100;i++){
            double mid=(high-low)/2.0+low;
            if(calculatearea(mid)>=halfarea){
                high=mid;
            }
            else low =mid;
        }
        return high;
    }
};