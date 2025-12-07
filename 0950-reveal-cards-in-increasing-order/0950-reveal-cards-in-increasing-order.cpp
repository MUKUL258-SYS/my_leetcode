class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int>q;
        int n=deck.size();
        for(int i=0;i<n;i++)q.push(i);
        sort(deck.begin(),deck.end());
        vector<int>ans(n);
        int j=0;
        while(!q.empty()){
            int idx=q.front();
            ans[idx]=deck[j++];
            q.pop();
            if(!q.empty()){
                int x=q.front();
                q.pop();
                q.push(x);
            }
        }
        return ans;

    }
};