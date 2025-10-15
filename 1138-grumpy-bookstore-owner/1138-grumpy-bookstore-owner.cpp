class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int s=0;
        int gain=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(!grumpy[i])s+=customers[i];
            else if(i<minutes){
               gain+=customers[i];
            }
        }
        maxi=gain;
        for(int i=1;i+minutes<=n;i++){
            if(grumpy[i-1]){
                gain-=customers[i-1];
            }
            if(grumpy[i+minutes-1]){
                gain+=customers[i+minutes-1];
            }
            maxi=max(maxi,gain);
        }
        return maxi+s;
    }
};