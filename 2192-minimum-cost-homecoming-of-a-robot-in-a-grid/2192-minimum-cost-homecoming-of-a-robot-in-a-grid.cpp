class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int ans=0;
        int i=startPos[0];
        int j=startPos[1];
        int ei=homePos[0];
        int ej=homePos[1];
        while(i!=ei){
            i+=((ei-i)/abs(ei-i));
            ans+=rowCosts[i];
        }
        while(j!=ej){
            j+=((ej-j)/abs(ej-j));
            ans+=colCosts[j];
        }
        return ans;
    }
};