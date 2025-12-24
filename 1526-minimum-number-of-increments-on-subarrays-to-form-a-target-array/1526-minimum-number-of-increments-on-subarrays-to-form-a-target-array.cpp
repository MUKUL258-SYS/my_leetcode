class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ops=0;
        ops+=target[0];
        int n=target.size();
        for(int i=1;i<n;i++){
       if(target[i]>target[i-1])ops+=(target[i]-target[i-1]);
        }
        return ops;
    }
};