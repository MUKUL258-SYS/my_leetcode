class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans="";
        int m=nums[0].size();
        int i=0,k=0;
        int n=nums.size();
        while(k<m&&i<n){
            if(nums[i][k]=='0')ans+='1';
            else ans+='0';
            k++;
            i++;
        }
        return ans;
    }
};