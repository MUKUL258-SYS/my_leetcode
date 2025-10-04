class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
       unordered_map<int,vector<int>>mp;
        sort(rectangles.begin(),rectangles.end());
        for(auto i:rectangles){
            int x=i[0];
            int y=i[1];
            mp[y].push_back(x);
        }
        vector<int>vp;
        for(auto j:points){
            int x=j[0];
            int y=j[1];
            int cnt=0;
           for(auto &[y2,v]:mp){
    
            if(y2>=y){
               auto it=lower_bound(v.begin(),v.end(),x);
             if(it!=v.end())cnt+=(v.end()-it);
            }
           }
           vp.push_back(cnt);
        }
        return vp;

    }
    
    
};
