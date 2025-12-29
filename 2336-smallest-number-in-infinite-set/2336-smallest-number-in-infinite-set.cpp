class SmallestInfiniteSet {
public:
set<int>s;
    SmallestInfiniteSet() {
        for(int i=1;i<=1001;i++)s.insert(i);
    }
    
    int popSmallest() {
        int p=-1;
        if(s.size()){
            p=*(s.begin());
            s.erase(s.begin());
        }
        return p;
    }
    
    void addBack(int num) {
        s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */