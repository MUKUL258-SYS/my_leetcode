class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        /*int n=points.size();
       sort(points.begin(),points.end(),[](const vector<int>&a,const vector<int>&b){
      if(a[0]!=b[0]){
        return a[0]<b[0];
      }
      return a[1]>b[1];
       });

       int cnt=0;
       vector<vector<int>>p=points;
       for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
        if((p[i][0]<p[j][0])&&(p[i][1]<p[j][1]))continue;
        
        cnt++;
        
        }
       // cnt++;
       */

       sort(points.begin(),points.end(),[](const vector<int>&a,const vector<int>&b){
      if(a[0]!=b[0]){
        return a[0]<b[0];
      }
      return a[1]>b[1];
       });
       vector<vector<int>>p=points;
       int cnt=0;
       int n=points.size();
       for(int i=0;i<n;i++){
           for(int j=i+1;j<n;j++){
           // if(i==j)continue;
            if((p[i][0]<p[j][0])&&(p[i][1]<p[j][1]))continue;
            bool f=true;
            for(int k=i+1;k<j;k++){
              //  if(k==i||k==j)continue;

                int x=p[k][0];
                int y=p[k][1];
                int x1=p[i][0];
                int y1=p[i][1];
                int x2=p[j][0];
                int y2=p[j][1];
                if((x1<=x)&&(x<=x2)&&(y2<=y)&&(y<=y1)){
                    f=false;
                    break;
                }
                
               
            }
            if(f)cnt++;
           }
       }

       return cnt;
    }
};