class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m=nums2.size();
        int n=nums1.size();
        int x=0;
        for(auto i:nums2){
            x=x^i;
        }
        if((m%2==0)&&(n%2==0)){
            cout<<"0"<<endl;
            return 0;
        }
        int y=0;
        for(auto i:nums1){
            y=y^i;
        }
        if(m%2==0){
            return x;
        }
        else if(n%2==0){
            return y;
        }
        return x^y;
    }
};