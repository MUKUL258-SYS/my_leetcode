/*class Solution {
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
           for(auto i:mp){
            vector<int>v=i.second;
            if(i.first>=y){
               auto it=lower_bound(v.begin(),v.end(),x);
               cnt+=(v.end()-it);
            }
           }
           vp.push_back(cnt);
        }
        return vp;

    }
    
    
};
*/

class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        sort(rectangles.begin(),rectangles.end());
        int n=rectangles.size();
        map<int,vector<int>> he;
        vector<int> ret;
        for(int i=0;i<n;i++)
        {
            int l=rectangles[i][0];
            int h=rectangles[i][1];
            he[h].push_back(l);
        }
        int p=points.size();
        for(int i=0;i<p;i++)
        {
            int cnt=0;
            int l=points[i][0];
            int h=points[i][1];
            for(auto& [x,lst]:he)
            {
                if(x<h)
                continue;
                else
                {
                    auto it = lower_bound(lst.begin(),lst.end(),l);
                    if(it!=lst.end())
                    {
                        cnt+=lst.size()-(it-lst.begin());
                    }
                }
            }
            ret.push_back(cnt);
        }
        return ret;
    }
};