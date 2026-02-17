class Solution {
public:

    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>vp;
        for(int h=0;h<12;h++){
            for(int m=0;m<60;m++){
                int cnt=__builtin_popcount(h)+__builtin_popcount(m);
                if(cnt==turnedOn){
                    string hour;
                hour=(to_string(h));
                   string minutes="";
                   if(m<10){
                      minutes+="0";
                   }
                   minutes+=to_string(m);
                   vp.push_back(hour+":"+minutes);

                }
            }
        }
        return vp;
    }
};