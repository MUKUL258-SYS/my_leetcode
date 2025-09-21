class Spreadsheet {
public:
vector<vector<int>>v;
int find_value(string cell){
  char ch=cell[0];
  if(ch>='A'&&ch<='Z'){
           int col=cell[0]-'A';
         int row=stoi(cell.substr(1));
        return v[row][col];
  }
  return stoi(cell);
}
    Spreadsheet(int rows) {
                v.resize(rows+1,vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
         int col=cell[0]-'A';
         int row=stoi(cell.substr(1));
         v[row][col]=value;
    }
    
    void resetCell(string cell) {
        int col=cell[0]-'A';
         int row=stoi(cell.substr(1));
         v[row][col]=0;
    }
    
    int getValue(string formula) {
        auto idx=formula.find('+');
        int v2=find_value(formula.substr(idx+1));
        int v1=find_value(formula.substr(1,idx-1));
        return v1+v2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */