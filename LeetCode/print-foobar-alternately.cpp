class FooBar {
private:
    int n;
    atomic<bool> flag;

public:
    FooBar(int n) {
        this->n = n;
        flag = false;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            while(flag) ;
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            flag = true;
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            while(!flag) ;
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            flag = false;
        }
    }
};