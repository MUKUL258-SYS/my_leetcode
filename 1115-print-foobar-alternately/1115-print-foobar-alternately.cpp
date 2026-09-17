class FooBar {
private:
    int n;

public:
    FooBar(int n) {
        this->n = n;
    }
    atomic<bool>runFoo=true;

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            
        	// printFoo() outputs "foo". Do not change or remove this line.
         while(!runFoo);
         printFoo();
         runFoo=false;
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            
        	// printBar() outputs "bar". Do not change or remove this line.
            while(runFoo);
            printBar();
            runFoo=true;
        }
    }
};