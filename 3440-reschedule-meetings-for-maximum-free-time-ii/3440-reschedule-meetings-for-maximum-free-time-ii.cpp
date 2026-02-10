class Solution {
public:
    int maxFreeTime(int e, vector<int>& st, vector<int>& et) {
        int n=st.size();
        vector<int>gaps;
        gaps.push_back(st[0]);
        for(int i=1;i<n;i++){
            gaps.push_back(st[i]-et[i-1]);
        }
        gaps.push_back(e-et.back());
        int cnt=0;
        for(auto i:gaps)if(i>0)cnt++;

        //int max_right=0;
        //int max_left=0;
        //for(auto i:gaps)max_right=max(max_right,i);
       int m=gaps.size();
       vector<int>v1,v2(m);
       int maxi=0;
       for(int i=m-1;i>=0;i--){
          maxi=max(maxi,gaps[i]);
          v1.push_back(maxi);
       }
       reverse(v1.begin(),v1.end());
         maxi=0;
         for(auto i:gaps)maxi=max(maxi,i);
         int max_left=0;
       for(int i=0;i<n;i++){
           int curr=et[i]-st[i];
           int max_right=i+2<m?v1[i+2]:0;
           //int left_gap=i>0?st[i]-et[i-1]:st[i];
           //int right_gap=i+1<n?st[i+1]-et[i]:e-et[i];
          // int max_left=(i-1>=0?v2[i-1]:0);
           if(curr<=max(max_right,max_left)){
     maxi=max(maxi,curr+gaps[i]+gaps[i+1]);
           }
           else{
            maxi=max(maxi,gaps[i]+gaps[i+1]);
           }
           max_left=max(max_left,gaps[i]);
           //v2[i]=maxi2;
           
        }
        
        
        return maxi;

    }
};