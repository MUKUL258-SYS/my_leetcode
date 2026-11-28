class Solution {
public:
vector<int>nums;
int k;
bool helper(int mid){
    long long sum=0;
    int cnt=1;
    for(auto i:nums){
        if(sum+i>mid){
            sum=i;
            cnt++;
        }
        else{
            sum+=i;
        }
        
    }
    return cnt<=k;
}
    int splitArray(vector<int>& nums, int k) {
        int s=INT_MIN,e=0;
        for(auto el:nums){e+=el;
            s=max(s,el);
        }
        this->nums=nums;
        this->k=k;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(helper(mid))e=mid-1;
            else s=mid+1;
        }
        return s;

    }
};