class Solution {
public:
    int minimumRefill(vector<int>& plants, int A, int B) {
        int n=plants.size();
        int i=0;
        int j=n-1;
        int cnt=0;
        int a=A;
        int b=B;
        while(i<=j){
            if(i==j){
              if(max(A,B)<plants[i])cnt++;
                
                break;
            }
            if(plants[i]<=A){
                A-=plants[i];
            }
            else{
                cnt++;
                A=a;
                A-=plants[i];

            }
            if(plants[j]<=B){
                B-=plants[j];
            }
            else{
                cnt++;
                B=b;
                 B-=plants[j];
            }
            i++;
            j--;
        }
        return cnt;
    }
};