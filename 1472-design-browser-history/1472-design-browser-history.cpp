class BrowserHistory {
public:
stack<string>history;
stack<string>future;
    BrowserHistory(string homepage) {
        history.push(homepage);
    }
    
    void visit(string url) {
        history.push(url);
        while(future.size())future.pop();
    }
    
    string back(int steps) {
         int s=steps;
        while(s>0&&history.size()>1){
          future.push(history.top());
          history.pop();
          s--;
        }
        // return future.size()?future.top():"";
         return history.size()?history.top():"";
    }
    
    string forward(int steps) {
        int s=steps;
        while(s>0&&future.size()>0){
          history.push(future.top());
          future.pop();
          s--;
        }
        // return future.size()?future.top():history.top();
   return history.size()?history.top():"";
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */