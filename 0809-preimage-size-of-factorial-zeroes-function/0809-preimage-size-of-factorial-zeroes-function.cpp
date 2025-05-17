class Solution {
public:
int helper(int n){
    int c=0;
    while(n){
         c+=(n/5);
         n/=5;
    }
    return c;
}
    int preimageSizeFZF(int k) {
    
        int s=0;
        int e=1e9;
        if(k==e)return 5;
        while(s<=e){
            int mid=(s+e)/2;
            int val=helper(mid);
            if(val==k)return 5;
            else if(val>k)e=mid-1;
            else s=mid+1;
            
        }
        return 0;
        

    }
};