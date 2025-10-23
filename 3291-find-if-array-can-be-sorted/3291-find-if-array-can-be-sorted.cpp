class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int cnt=-1;
        int currMin=1e9,currMax=-1,prevMax=-1;
        for(auto i:nums){
            int currBits=__builtin_popcount(i);
            if(cnt==-1||currBits==cnt){
                currMax=max(currMax,i);
                currMin=min(currMin,i);
            }
            else{
                if(prevMax>currMin)return false;
                prevMax=currMax;
                currMin=i;
                currMax=i;

            }
            cnt=currBits;
        }
        if(prevMax>currMin)return false;
        return true;
    }
};