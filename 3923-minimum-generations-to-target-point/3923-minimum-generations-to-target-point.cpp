class Solution {
public:
vector<int> helper(vector<int>& v1, vector<int>& v2) {
        vector<int> res;
        for (int i = 0; i < 3; i++)
            res.push_back((v1[i] + v2[i]) / 2);
        return res;
    }
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
           set<vector<int>>s;
           for(auto i:points)s.insert(i);
           if(s.count(target))return 0;
           int n=points.size();
           if(n==1)return -1;
           int k=0;
           while(!s.count(target)){
            vector<vector<int>>ad;
            int n=points.size();
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    vector<int>mid=helper(points[i],points[j]);
                    if(!s.count(mid)){
                        ad.push_back(mid);
    s.insert(mid);
                    }
                }
            }
            if(ad.size()==0)return -1;
            for(auto &i:ad){
                //s.insert(i);
                points.push_back(i);
            }
            k++;
           }
           return k;
    }
};