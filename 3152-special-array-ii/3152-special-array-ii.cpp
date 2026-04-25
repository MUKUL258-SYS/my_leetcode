class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>vp(n,0);
        int cnt=1;
        vp[0]=1;
        for(int i=1;i<n;i++){
            int diff=abs((nums[i]%2)-(nums[i-1]%2));
            if(diff!=1){
                cnt=1;
            }
            else cnt++;
            vp[i]=cnt;
        }
        for(auto i:vp){
            cout<<i<<" ";
        }
       // return {};
        
        vector<bool>res;
        for(auto i:queries){
            int l=i[0];
            int r=i[1];
            //int diff=vp[r]-(l-1>=0?vp[l-1]:0);
            if(vp[r]>=(r-l+1)){
                res.push_back(true);
            }
            else res.push_back(false);
        }
        return res;
    }
};