class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            set<int>s1,s2;
            for(int j=i;j<n;j++){
                if(nums[j]%2==0)s1.insert(nums[j]);
                else s2.insert(nums[j]);
                if(s1.size()==s2.size())maxi=max(maxi,j-i+1);
        }
        }
        return maxi;
    }
};