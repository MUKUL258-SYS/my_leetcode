class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        if(nums1==nums2)return 0;
        unordered_map<int,int>mp1,mp2;
        for(auto i:nums1)mp1[i]++;
        for(auto i:nums2)mp2[i]++;
        for(auto i:nums2){
            if(mp1[i]==0){
                if(mp2[i]%2)return -1;
            }
        }
        for(auto i:nums1){
            if(mp2[i]==0){
                if(mp1[i]%2)return -1;
            }
        }
    unordered_map<int,int>res;
    for(auto i:nums1)res[i]++;
    for(auto i:nums2)res[i]++;
    for(auto &i:res){
        if(i.second%2)return -1;
        i.second=(i.second/2);
    }
    int v1=0,v2=0;
    for(auto i:res){
        v1+=abs(i.second-mp1[i.first]);
        v2+=abs(i.second-mp2[i.first]);
    }
    return min(v1/2,v2/2);
    

    

        
    }
};