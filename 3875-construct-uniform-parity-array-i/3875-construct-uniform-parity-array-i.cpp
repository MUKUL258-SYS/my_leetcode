class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int cnto=0;
        int cnte=0;
        int n=nums1.size();
        for(auto i:nums1){
            if(i%2)cnto++;
            else cnte++;
        }
        if(cnte==n || cnto==n)return true;
        return true;

    }
};