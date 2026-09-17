class ZeroEvenOdd {
private:
    int n;
   atomic<int> i{1};
   binary_semaphore sz{1};
   binary_semaphore se{0};
   binary_semaphore so{0};
public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(true){
         sz.acquire();
         if(i>n){
            so.release();
            se.release();
            break;
         }
         printNumber(0);
         if(i%2){
            so.release();
         }
         else se.release();
        }
    }

    void even(function<void(int)> printNumber) {
        while(true){
            se.acquire();
            if(i>n){
                se.release();
                break;
            }
            printNumber(i++);
            sz.release();
        }
    }

    void odd(function<void(int)> printNumber) {
        while(true){
        so.acquire();
        if(i>n){
            so.release();
            break;
        }
        printNumber(i++);
        sz.release();
        }
    }
};