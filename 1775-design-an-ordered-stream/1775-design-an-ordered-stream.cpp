class OrderedStream {
public:
map<int,string>stream;
vector<string>s;
int ptr=1;
int size;
    OrderedStream(int n) {
        size=n+1;
        s.resize(size);
    }
    
    vector<string> insert(int idKey, string value) {
          s[idKey] = value;
        vector<string> res;
        while(ptr < size && !s[ptr].empty()) res.push_back(s[ptr++]);
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */