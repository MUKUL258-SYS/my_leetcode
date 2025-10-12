class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int a) {
        vector<int>v;
        int n=rocks.size();
        for(int i=0;i<n;i++){
            v.push_back(capacity[i]-rocks[i]);
        }
        sort(v.begin(),v.end());
        n=v.size();
        int s=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            s+=v[i];
         if(s>a)break;
         cnt++;
        }
        return cnt;
    }
};