class Solution {
public:
    int kthGrammar(int n, int k) {
        int l=1;
        int r=1<<(n-1);
        int cost=0;
      //  n--;
        while(n>0){
         int mid=(l+r)/2;
         if(k<=mid){
            r=mid;
         }
         else{
            l=mid+1;
            cost=cost==0?1:0;
         }
         n--;
        }
        return cost;
    }
};