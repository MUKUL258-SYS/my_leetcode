class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        long long sum=0;
        int n=values.size();
        int m=values[0].size();
       // vector<priority_queue<int,vector<int>,greater<int>>>vp;
     priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq; 
     for(int i=0;i<n;i++){
        pq.push({values[i][m-1],i,m-1});
     }
     long long d=1;
     while(!pq.empty()){
       vector<int>p=pq.top();
       pq.pop();
       int value=p[0];
       int i=p[1];
       int j=p[2];
       sum=(sum+value*d);
       d++;
       j--;
       if(j>=0){
        pq.push({values[i][j],i,j});
       }
     }
     return sum;
        

    }
};