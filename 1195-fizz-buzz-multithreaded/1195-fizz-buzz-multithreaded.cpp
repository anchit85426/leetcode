class FizzBuzz {
private:
    int n;
    std::mutex m;
    std::condition_variable cv;
    int i;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->i=1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(i<=n){
        std::unique_lock<std::mutex>lock(m);
        while(i<=n and (i%3==0 and i%5!=0)==0){
            cv.wait(lock);
        }
        if(i<=n){
            printFizz();
            i++;
        }
        cv.notify_all();
    }
}
    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(i<=n){
        std::unique_lock<std::mutex>lock(m);
        while(i<=n and (i%3!=0 and i%5==0)==0){
            cv.wait(lock);
        }
        if(i<=n){
            printBuzz();
            i++;
        }
        cv.notify_all();
    }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(i<=n){
        std::unique_lock<std::mutex>lock(m);
        while(i<=n and (i%3==0 and i%5==0)==0){
            cv.wait(lock);
        }
        if(i<=n){
            printFizzBuzz();
            i++;
        }
        cv.notify_all();
    }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(i<=n){
        std::unique_lock<std::mutex>lock(m);
        while(i<=n and (i%3!=0 and i%5!=0)==0){
            cv.wait(lock);
        }
        if(i<=n){
            printNumber(i);
            i++;
        }
        cv.notify_all();
    }
    }
};