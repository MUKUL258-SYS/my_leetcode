class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        sort(a.begin(),a.end());
        int idx=-1;
        int n=a.size();
        for(int i=0;i<n;i++){
           if(a[i]<=mass){
              idx=i;
           }
        }
        if(idx==-1)return false;
long long sum=mass;
        for(int i=0;i<=idx;i++){
            sum+=a[i];
        }
        for(int i=idx+1;i<n;i++){
            if(sum<a[i])return false;
            sum+=a[i];
        }
        return true;
    }
};