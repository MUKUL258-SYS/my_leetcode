class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        vector<vector<int>>arr;
       // for(auto i:arrays){
         //   arr.push_back({i[0],i.back()});
        //}
          priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq1;
          priority_queue<pair<int,int>>pq2;

        for(int i=0;i<arrays.size();i++){
           // arr.push_back({arrays[i][0],arrays[i][1],i});
           pq1.push({arrays[i][0],i});
           pq2.push({arrays[i].back(),i});
        }
       // sort(arr.begin(),arr.end());
       pair<int,int>p1=pq1.top();
       pq1.pop();
       pair<int,int>p2=pq1.top();
       pq1.pop();
       pair<int,int>p3=pq2.top();
       pq2.pop();
       pair<int,int>p4=pq2.top();
       pq2.pop();
       int idx1=p1.second;
       int idx2=p2.second;
       int idx3=p3.second;
       int idx4=p4.second;
       if(idx1!=idx3){
        return abs(p1.first-p3.first);
       }
       int v1=abs(p1.first-p4.first);
       int v2=abs(p2.first-p3.first);
       return max(v1,v2);
      

    }
};