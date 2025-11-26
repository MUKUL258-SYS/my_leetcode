class Solution {
public:
    /*int longestPalindrome(vector<string>& words) {
        map<string,int>mp;
        string str;
        int maxi=0;
        for(auto i:words){
            mp[i]++;
        }
        for(auto i:mp){
             if(i.first[0]==i.first[1]&&(i.second%2==1)){

                maxi=max(maxi,i.second);
                str=i.first;
            }
        }
        
        long long res=0;
        res+=maxi;
        for(auto &i:mp){
            if(i.first[0]==i.first[1]){
                if(i.second%2==0)res+=i.second;
               else{
                if(i.first!=str){
                    res+=(i.second-1);
                }
               }
            }
        }
        cout<<res<<endl;
         for (auto &i : mp) {
        string s = i.first;

        if (s[0] == s[1]) continue; // skip palindromic strings

        string rev = "";
        rev += s[1];
        rev += s[0];

        // take min count from s and rev
        int pairs = 2*min(mp[s], mp[rev]);
        res += pairs;

        // IMPORTANT FIX:
        // clear both entries so they are NOT counted again
        mp[s] = 0;     
        mp[rev] = 0;   
    }

        return 2*res;
    }*/
    int longestPalindrome(vector<string>& words) {
    map<string,int> mp;

    // counting words
    for (auto &i : words) mp[i]++;

    string centerWord = "";
    int centerCount = 0;

    // find the palindromic word with max odd count
    for (auto &i : mp) {
        if (i.first[0] == i.first[1] && (i.second % 2 == 1)) {
            if (i.second > centerCount) {
                centerCount = i.second;
                centerWord = i.first;
            }
        }
    }

    long long res = 0;

    // add the center palindrome word count
    res += centerCount;

    // handle other palindromic words
    for (auto &i : mp) {
        if (i.first[0] == i.first[1]) {
            if (i.first == centerWord) continue; // skip the center one

            if (i.second % 2 == 0) res += i.second;
            else res += (i.second - 1);
        }
    }

    // handle non-palindromic reverse pairs
    for (auto &i : mp) {
        string s = i.first;

        if (s[0] == s[1]) continue; // skip palindromic strings

        string rev = "";
        rev += s[1];
        rev += s[0];

        // take min count from s and rev
        int pairs = 2* min(mp[s], mp[rev]);
        res += pairs;

        // IMPORTANT FIX:
        // clear both entries so they are NOT counted again
        mp[s] = 0;     
        mp[rev] = 0;   
    }

    return res * 2; // each word contributes length 2
}

};

