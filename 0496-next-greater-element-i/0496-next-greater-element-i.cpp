class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        stack<int>st;
        vector<int>ans(n,-1);
         unordered_map<int,int>mp;
         for(int i=0;i<n;i++){
            mp[nums1[i]]=i+1;
         }
         for(auto i:nums2){
            
                while(st.size() && i>st.top()){
                 if(mp[st.top()]>0)ans[mp[st.top()]-1]=i;
                 st.pop();
                }
                st.push(i);
            
         }
         return ans;

    }
};