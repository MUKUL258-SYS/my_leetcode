class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>dq;
        int fliphistory=0,flips=0;

        for(int i=0;i<n;i++){
            if(i>=k){
               fliphistory-=dq.front();
               dq.pop_front();
            }
            if(fliphistory%2 == nums[i]){
                if(i+k>n)return -1;
            flips++;
            fliphistory++;
             dq.push_back(1);
            }
            else dq.push_back(0);
        }
        return flips;
    }
};