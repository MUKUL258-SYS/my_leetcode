class Solution {
public:
    int primeSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        multiset<int>s;
        deque<int>q;
        vector<int>primes;
        for(auto &i:nums){
            if(i==1){
            primes.push_back(0);
            continue;
            }
            int prime=1;
            for(int j=2;j*j<=i;j++){
                if(i%j==0){
                  prime=0;
                  break;
                }
            }
            primes.push_back(prime);
        }
        int l=0;
        for(int r=0;r<n;r++){
            if(primes[r]){
                q.push_back(r);
                s.insert(nums[r]);
            }
            while(!s.empty()&&*s.rbegin()-*s.begin()>k){
                if(primes[l]){
            s.erase(s.find(nums[l]));
                q.pop_front();
                }
                l++;

            }
            if(!q.empty()&&(int)q.size()>=2){
                int a=q.back();
                q.pop_back();
                int b=q.back();
                q.pop_back();
                ans+=(b-l+1);
                q.push_back(b);
                q.push_back(a);
            }

        }
        return ans;
    }
};