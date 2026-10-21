class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        auto mx=*max_element(s.begin(),s.end());
        auto mn=*min_element(s.begin(),s.end());
        string t=s;
        sort(t.begin(),t.end());
        if(s==t)return 0;
        if(n==2)return -1;
        if(s[0]==mn || s[n-1]==mx)return 1;
        for(int i=1;i<n-1;i++)if(s[i]==mx || s[i]==mn)return 2;
        return 3;
    }
};