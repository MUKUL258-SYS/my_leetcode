class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        
       int n=nums.size();
       vector<int>bits(32,0);
       int i=0;
       int mini=INT_MAX;
       int currentor=0;
       for(int j=0;j<n;j++){
       currentor |= nums[j];
        for(int bit=0;bit<32;bit++){
            if(nums[j] & (1<<bit)){
               // currentor|=(1<<bit);
               bits[bit]++;
            }
        }
        while(i<=j && currentor>=k){
      mini=min(mini,j-i+1);
      int upor=0;
       for(int bit=0;bit<32;bit++){
            if(nums[i] & (1<<bit)){
                bits[bit]--;
                //if(bits[bit]>0)upor |= (1<<bit);
            }
            if(bits[bit]>0)upor |= (1<<bit);
        }
        currentor=upor;
        i++;

        }
       }
       return mini==INT_MAX?-1:mini;
    }
};