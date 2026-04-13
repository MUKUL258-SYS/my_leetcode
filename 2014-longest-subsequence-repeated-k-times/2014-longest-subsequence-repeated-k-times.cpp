/*class Solution {
public:
string res="";
bool isSub(string &s, string &sub,int k){
  /*  int i=0,j=0;
    int cnt=0;
    int n=s.size();
    int m=t.size();
    for(int i=0;i<n;i++){
        if(s[i]==t[j]){
            j++;
        }
        if(j==m){
            cnt++;
            j=0;
        }
    }
    return cnt>=k;
  
    int i = 0;
        int j = 0;
        int L = sub.length();
        int n = s.length();

        while(i < n && j < k*L) {
            if(s[i] == sub[j%L])
                j++;
            
            i++;
        }

        return j == k * L;
}
bool dfs(int len,vector<int>&freq,string &s,string &t,int k){
    if(s.size()==len){
        if(isSub(t,s,k)){
            res=s;
            return true;
        }
        return false;
    }
    for(int i=25;i>=0;i--){
        if(freq[i]==0)continue;
        freq[i]--;
        s+=(i+'a');
        if(dfs(len,freq,s,t,k))return true;
        s.pop_back();
        freq[i]++;
    }
    return false;
}



    string longestSubsequenceRepeatedK(string s, int k) {
        //unordered_map<char,int>mp;
        vector<int>v(26,0);
        for(auto i:s)v[i-'a']++;
        int maxi=0;
        int n=s.size();
        for(auto &i:v){
            maxi=max(maxi,i);
            if(i>k)i=i/k;
        }
        if(maxi<k)return "";
        int maxlen=n/k;
    
        for(int i=maxlen;i>=1;i--){
            vector<int>temp=v;
            string t="";
            if(dfs(i,temp,t,s,k)){
             return res;
            }
        }
        return res;

      
    }
};

*/
class Solution {
public:
    string result = "";

    bool isSubsequence(string &s, string& sub, int k) {
        int i = 0;
        int j = 0;
        int L = sub.length();
        int n = s.length();

        while(i < n && j < k*L) {
            if(s[i] == sub[j%L])
                j++;
            
            i++;
        }

        return j == k * L;
    }

    bool backtracking(string& s, string &curr, vector<bool>& canUse, vector<int>& requiredFreq, int k, int maxLen) {
        if(curr.length() == maxLen) {
            if(isSubsequence(s, curr, k)) {
                result = curr;
                return true;
            }
            return false;
        }

        for(int i = 25; i >= 0; i--) {
            if(canUse[i] == false || requiredFreq[i] == 0)
                continue;
            
            //DO
            char ch = i + 'a';
            curr.push_back(ch);
            requiredFreq[i]--;

            //EXPLORE
            if(backtracking(s, curr, canUse, requiredFreq, k, maxLen) == true) {
                return true;
            }

            //UNDO
            curr.pop_back();
            requiredFreq[i]++;

        }

        return false;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.length();

        int freq[26] = {};
        for(char &ch : s) {
            freq[ch-'a']++;
        }

        vector<bool> canUse(26, false);
        vector<int> requiredFreq(26, 0);
        for(int i = 0; i < 26; ++i) {
            if(freq[i] >= k) {
                canUse[i] = true;
                requiredFreq[i] = freq[i]/k; //atmost this can be used in a subsequence
            }
        }

        int maxLen = n / k;

        for(int len = maxLen; len >= 0; len--) {
            vector<int> tempRequiredFreq = requiredFreq;
            string curr = "";
            if(backtracking(s, curr, canUse, tempRequiredFreq, k, len) == true) {
                return result;
            }
        }

        return result;


    }
};


//Approach-2 IMPROVED B