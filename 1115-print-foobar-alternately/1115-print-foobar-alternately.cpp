class FooBar {
private:
    int n;

public:
    binary_semaphore s1{1};
    binary_semaphore s2{0};
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            
        	// printFoo() outputs "foo". Do not change or remove this line.
            s1.acquire();
        	printFoo();
            s2.release();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            s2.acquire();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            s1.release();
        }
    }
};