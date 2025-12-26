class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n=nums.size();
        vector<int>v(n,-1);
        for(int i=0;i<n;i++){
             
            int idx=index[i];
            for(int j=n-2;j>=idx;j--){
                v[j+1]=v[j];
            }
            v[idx]=nums[i];
            for(auto i:v){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        return v;
    }
};