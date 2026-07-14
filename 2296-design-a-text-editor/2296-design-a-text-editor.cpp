class TextEditor {
public:
stack<char>left;
stack<char>right;
    TextEditor() {
        
    }
    
    void addText(string text) {
        for(auto i:text)left.push(i);
    }
    
    int deleteText(int k) {
        int cnt=0;
        while(!left.empty() && k>0){
            left.pop();
            k--;
            cnt++;
        }
        return cnt;

    }
    
    string cursorLeft(int k) {
        while(left.size() && k>0){
           right.push(left.top());
           left.pop();
           k--;
        }
        return helper();
    }
    
    string cursorRight(int k) {
        while(right.size() && k>0){
            left.push(right.top());
            right.pop();
            k--;
        }
        return helper();
    }
    string helper(){
     string res="";
     int mini=min(10,(int)left.size());
     while(left.size() && mini>0){
        res+=left.top();
        left.pop();
        mini--;
     }
     //string ans=res;
     reverse(res.begin(),res.end());
  for(auto ch:res)left.push(ch);
  return res;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */