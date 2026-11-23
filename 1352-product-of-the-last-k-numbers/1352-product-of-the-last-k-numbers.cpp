class ProductOfNumbers {
public:
vector<long long>pre;
    ProductOfNumbers() {
        pre={1};
    }
    
    void add(int num) {
      
        if(num==0){
            pre={1};
        }
        else {
            pre.push_back(pre.back()*num);
        }
    }
    
    int getProduct(int k) {
    int n=pre.size();
    if(n-(k+1)>=0)return pre.back()/pre[pre.size()-k-1];
    return 0;
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */