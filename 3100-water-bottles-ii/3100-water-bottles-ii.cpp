class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
      /* int res=0;
        while(true){
            if(numBottles<numExchange)break;
            res+=numBottles;
            int empty=numBottles;
            numBottles+=1;
            numExchange++;
        }
        */
        int ans=numBottles;
        int empty=numBottles;
        while(empty>=numExchange){
            ans++;
            empty-=numExchange;
            empty++;
            numExchange++;
        }
        return ans;
    }
};