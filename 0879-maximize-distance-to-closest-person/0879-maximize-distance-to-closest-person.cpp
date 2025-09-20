class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        int prev=-1;
        int maxi=-1;
        for(int i=0;i<n;i++){
            if(seats[i]&&prev==-1){
                maxi=max(maxi,i);
                prev=i;
            }
           else if(seats[i]){
             maxi=max(maxi,(i-prev)/2);
             prev=i;
            }
        }
      //  maxi=max(maxi,)
    if(prev!=-1)maxi=max(maxi,n-1-prev);
        return maxi;
    }
};