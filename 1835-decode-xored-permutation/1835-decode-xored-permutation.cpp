class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int v1=0;
        int n=encoded.size();
        for(int i=1;i<=n+1;i++){
            v1=v1^i;
        }
        int v2=0;
        for(int i=0;i<n;i+=2){
            v2=v2^encoded[i];
        }
        int last=v1^v2;
        vector<int>v;
        v.push_back(last);
        for(int i=n-1;i>=0;i--){
            int second_last=last^encoded[i];
           v.push_back(second_last);
           last=second_last;

        }
        reverse(v.begin(),v.end());
     return v;
    }
};