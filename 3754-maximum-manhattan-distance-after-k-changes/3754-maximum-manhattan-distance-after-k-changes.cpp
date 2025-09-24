class Solution {
public:
    int maxDistance(string s, int k) {
        int ans=0;
        for(auto ydir:{'N','S'}){
            for(auto xdir:{'E','W'}){
                int remainingK=k,xnet=0,ynet=0;
                for(auto ch:s){
                    if(ch==ydir&&remainingK){
                        ch=(ch=='N')?'S':'N';
                        remainingK--;
                    }
                    else if(ch==xdir&&remainingK){
                        ch=(ch=='E')?'W':'E';
                        remainingK--;
                    }
                    ynet+=(ch=='N');
                    ynet-=(ch=='S');
                    xnet+=(ch=='E');
                    xnet-=(ch=='W');
                   ans=max(ans,abs(xnet)+abs(ynet));
                }
            }
        }
        return ans;
    }
};