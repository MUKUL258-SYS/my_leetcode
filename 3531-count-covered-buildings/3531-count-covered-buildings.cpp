class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& b) {
       unordered_map<int,set<int>>mp1,mp2;
       for(auto i:b){
        mp1[i[0]].insert(i[1]);
        mp2[i[1]].insert(i[0]);
       }
     int cnt=0;
       for(auto i:b){
        int x=i[0];
        int y=i[1];
        //check if 1 smaller y is present and 1 greater is present through binary search

    //&&

        //check if 1 smaller x is present and 1 greateris present through binary search

        //if both are true do cnt++;

        auto &colset=mp1[x];
        auto &rowset=mp2[y];
        auto itr=colset.lower_bound(y);
        if(itr!=colset.begin()&&(next(itr)!=colset.end())){
            auto itr2=rowset.lower_bound(x);
            if(itr2!=rowset.begin()&&(next(itr2)!=rowset.end())){
                cnt++;
            }
        }
        
       }
       return cnt;

    }
};