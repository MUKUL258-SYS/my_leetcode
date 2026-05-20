class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score=0;
        int counter=0;
        for(auto i:events){
            char ch=i[0];
            if(ch>='0'&&ch<='6')score+=(ch-'0');
            else if(i=="W")counter+=1;
            else{
                score+=1;
            }
            if(counter==10)break;
        }
        return {score,counter};
    }
};