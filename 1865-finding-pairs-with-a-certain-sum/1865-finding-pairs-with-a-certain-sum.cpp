class FindSumPairs {
public:
unordered_map<int,int>mp1,mp2;
vector<int>nums1,nums2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1=nums1;
        this->nums2=nums2;
          for(auto i:nums1)mp1[i]++;
          for(auto i:nums2)mp2[i]++;

    }

    
    void add(int index, int val) {
       int old_value=nums2[index];
      mp2[old_value]--;
      if(mp2[old_value]==0)mp2.erase(old_value);
      nums2[index]+=val;
      mp2[nums2[index]]++;
    }
    
    int count(int tot) {
         int cnt=0;
         for(auto i:nums1){
            cnt+=mp2[tot-i];
         }
         return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */