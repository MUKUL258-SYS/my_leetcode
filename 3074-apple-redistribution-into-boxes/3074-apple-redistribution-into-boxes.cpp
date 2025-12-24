class Solution {
public:
    int minimumBoxes(vector<int>& a, vector<int>& c) {
        sort(c.begin(),c.end(),greater<int>());
        int sum=0;
        for(auto i:a)sum+=i;
        int cnt=0;
        for(auto i:c){
            if(sum<=0)break;;
            sum-=i;
            cnt++;
            
        }
        return cnt;
    }
};