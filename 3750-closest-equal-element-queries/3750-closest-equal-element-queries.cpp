/*class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>>mp;
        vector<int>arr=nums;
        for(auto i:nums)arr.push_back(i);
        for(auto i:nums)arr.push_back(i);
       int m=nums.size();
        int n=arr.size();
        for(int i=0;i<n;i++)mp[arr[i]].push_back(i);
    vector<int>ans;
        for(auto i:queries){
            
            if(mp[nums[i]].size()<=2){ans.push_back(-1);
            continue;
            }
            int mini=INT_MAX;
            vector<int>v=mp[nums[i]];
            //sort(v.begin(),v.end());
           
            for(auto i:v)cout<<i<<" ";
            cout<<endl;
            int idx=lower_bound(v.begin(),v.end(),i+m)-v.begin();
            
            if(idx-1>=0)mini=min(mini,v[idx]-v[idx-1]);
            if(idx+1<v.size())mini=min(mini,v[idx+1]-v[idx]);
            if(mini==m)mini=-1;
            ans.push_back(mini);
        }
        return ans;
    }
};
*/
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>> mp;
        vector<int> arr = nums;
        int m = nums.size();
        
        // Append nums twice more to simulate the circular array
        for(auto i: nums) arr.push_back(i);
        for(auto i: nums) arr.push_back(i);

        int n = arr.size();

        // Store indices of each element
        for(int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        vector<int> ans;

        for(auto i: queries) {
            int num = nums[i];
            if(mp[num].size() <= 3) {
                ans.push_back(-1);
                continue;
            }

            int mini = INT_MAX;
            vector<int>& v = mp[num];

            // Finding the first occurrence in the second segment
            int idx = lower_bound(v.begin(), v.end(), i + m) - v.begin();
            
            if (idx - 1 >= 0) mini = min(mini, v[idx] - v[idx - 1]);
            if (idx + 1 < v.size()) mini = min(mini, v[idx + 1] - v[idx]);

            if (mini == m) mini = -1;
            ans.push_back(mini);
        }
        return ans;
    }
};
