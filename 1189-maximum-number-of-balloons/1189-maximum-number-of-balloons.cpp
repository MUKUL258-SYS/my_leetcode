class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> s(5,0);
        for(auto i : text){
            if(i == 'b'){
                s[0]++;
            }
            else if(i == 'a'){
                s[1]++;
            }
            else if(i == 'l'){
                s[2]++;
            }
            else if(i == 'o'){
                s[3]++;
            }
            else if(i == 'n'){
                s[4]++;
            }
        }
        s[2] = s[2]/2;
        s[3] = s[3]/2;
        int h = *min_element(s.begin(),s.end());
        int f = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] < h){
                f = 1;
                break;
            }
        }
        if(f == 0){
            return h;
        }
        return 0;
    }
};