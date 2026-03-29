class Solution {
public:
    bool canBeEqual(string s1, string s2) {
         map<char,int>e1,o1,e2,o2;
        int n=s1.size();
        for(int i=0;i<n;i+=2){
            e1[s1[i]]++;
            e2[s2[i]]++;
        }
        for(int i=1;i<n;i+=2){
            o1[s1[i]]++;
            o2[s2[i]]++;
        }
        return (o1==o2&&e1==e2); 
    }
};