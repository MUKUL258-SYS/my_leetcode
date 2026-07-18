class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        set<int>s;
        int n=arr.size();
        if(n==m)return m;
        s.insert(0);
        s.insert(n+1);
        for(int i=n-1;i>=0;i--){
            int x=arr[i];
           // auto itr=upper_bound(s.begin(),s.end(),x);
           auto itr=s.upper_bound(x);
            int nextv=*itr;
            int prevv=*prev(itr);
            int l=nextv-x-1;
            int u=x-prevv-1;
            if(l==m || u==m)return i;
            s.insert(x);
        }
        return -1;
    }
};