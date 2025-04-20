class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<float>a;
        int n=speed.size();
        for(int i=0;i<n;i++){
            a.push_back((float)dist[i]/speed[i]);
        }
        sort(a.begin(),a.end());
        int ans=0;
        for(int i=0;i<a.size();i++){
            if(a[i]<=i)break;
            ans++;
        }
        return ans;
    }
};