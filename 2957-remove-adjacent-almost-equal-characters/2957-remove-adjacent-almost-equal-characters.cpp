class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int n=word.size();
        int cnt=0;
        for(int i=0;i+1<n;i++){
            if(word[i]==word[i+1]){
                cnt++;
                word[i]='$';
                word[i+1]='$';
            }
            else if(abs(word[i+1]-word[i])==1){
                cnt++;
                word[i]='$';
                word[i+1]='$';
            }
            
        }
        return cnt;
    }
};