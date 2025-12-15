class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        //vector<priority_queue<int>>v;
        int n=limit.size();
         vector<priority_queue<int,vector<int>,greater<int>>>v(n);
       for(int i=0;i<n;i++){
        
           auto &p=v[limit[i]-1];
           if(p.size()<limit[i]){
            p.push(value[i]);
           }
           else if(p.size()==limit[i]){
            if(p.top()<value[i]){
                p.pop();
                p.push(value[i]);
            }

           }

          // v[i]=p;
       }
       long long sum=0;
       for(auto &p:v){
        while(!p.empty()){
            sum+=p.top();
            p.pop();
        }
       }
       return sum;
    }
};