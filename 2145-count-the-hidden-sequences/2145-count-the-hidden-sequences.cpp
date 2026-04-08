class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) {
        long long sum=0;
        int n=diff.size();
       long long mini=LLONG_MAX;
       long long maxi=LLONG_MIN;
       for(auto i:diff){
        sum+=i;
        mini=min(mini,sum);
        maxi=max(maxi,sum);
       }
       int cnt=0;
       int s=-1e5;
       int e=1e5;
       for(int i=lower;i<=upper;i++){
        long long v1=mini+i;
        long long v2=maxi+i;
        if(v1>=lower&&v1<=upper){
            if(v2>=lower&&v2<=upper){
                cnt++;
            }
        }
       }
       return cnt;
    }
};