class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
       // if(k==0)return nums;
        vector<int>v;
        for(auto i:nums){
            if(i>=0)v.push_back(i);
        }
       //  if(k==0)return nums;
        int n=v.size();
         if(k==0||n==0)return nums;
        k=k%n;
       // if(k==0)return nums;
        vector<int>temp;
        for(int i=k;i<n;i++)temp.push_back(v[i]);
        for(int i=0;i<k;i++)temp.push_back(v[i]);
    int l=0;
    for(auto &i:nums){
         if(i>=0)i=temp[l++];
    }
    return nums;

    }
};