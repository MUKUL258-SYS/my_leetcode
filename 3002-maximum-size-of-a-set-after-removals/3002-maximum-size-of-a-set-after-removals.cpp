class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        set<int>s1,s2,s;
        for(auto i:nums1){
            s.insert(i);
            s1.insert(i);
        }
        for(auto i:nums2){
            s.insert(i);
            s2.insert(i);
        }
        int n=nums1.size();
       // return min((min(n/2,(int)s1.size()+min(n/2,(int)s2.size())),(int)s.size());
int v=min(n/2,(int)s1.size())+min(n/2,(int)s2.size());
return min(v,(int)s.size());
    }
};