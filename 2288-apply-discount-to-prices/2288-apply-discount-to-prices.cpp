class Solution {
public:
bool isPrice(string word){
    if(word.size()==0||word[0]!='$')return false;
    for(int i=1;i<word.size();i++){
        if(!isdigit(word[i]))return false;
    }
    return true;
}
    string discountPrices(string sentence, int discount) {
        stringstream str(sentence);
        string word;
        double discountPrice;
        string result;
        ostringstream oss;
        while(str>>word){
            if(isPrice(word)){
                word.erase(0,1);
                if(!word.empty()){
                 discountPrice=stod(word)-((discount*stod(word))/100);
        oss<<"$"<<fixed<<setprecision(2)<<discountPrice<<" ";
                }
                else{
                    oss<<"$"<<" ";
                }
            }else{
                oss<<word<<" ";
            }
        }
        result=oss.str();
        result.pop_back();
        return result;
    }
};