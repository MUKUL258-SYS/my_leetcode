class Cashier {
public:
unordered_map<int,int>mp;
int n,d,cnt;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
       int k=products.size();
       for(int i=0;i<k;i++){
        mp[products[i]]=prices[i];
       }
        this->n=n;
        d=discount;
        cnt=0;
    }
    
    double getBill(vector<int> product, vector<int> amount) {
      cnt++;
       double s=0;
        int k=product.size();
        for(int i=0;i<k;i++){
            s+=(mp[product[i]]*amount[i]);
        }
      if(cnt%n==0){
        return (s*(100-d))/100;
      }

      return s;     


        
        
   }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */