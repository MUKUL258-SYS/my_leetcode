class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int i=n-1;
        int carry=1;
        while(true){
         int d=(digits[i]+carry)%10;
          carry=(digits[i]+carry)/10;
          digits[i]=d;
          i--;
          if(!carry||i<0)break;
        }
    if(carry){
        reverse(digits.begin(),digits.end());
        digits.push_back(1);
        reverse(digits.begin(),digits.end());
    }
    return digits;
    }
};