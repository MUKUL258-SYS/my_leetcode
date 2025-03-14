class Solution {
public:
    vector<int> closestDivisors(int num) {
        int n1=num+1;
        int n2=num+2;
        int mini=INT_MAX;
        vector<int>ans;
        for(int i=1;i*i<=n1;i++){
              if(n1%i==0){
            if((n1/i)-i<mini){
                mini=(n1/i)-i;
                ans={n1/i,i};
            }
              }
        }
         for(int i=1;i*i<=n2;i++){
              if(n2%i==0){
               // mini=min(mini,(n2/i)-i);
               if((n2/i)-i<mini){
                mini=(n2/i)-i;
                ans={n2/i,i};
            }
              }
        }
        return ans;
    }
};