class MedianFinder {
public:
    priority_queue<int>Maxheap;
    priority_queue<int,vector<int>,greater<int>>Minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        Maxheap.push(num);
        Minheap.push(Maxheap.top());
        Maxheap.pop();
        if(Minheap.size()>Maxheap.size()){
            Maxheap.push(Minheap.top());
            Minheap.pop();
        }
    }
    
    double findMedian() {
        if(Maxheap.size()>Minheap.size()){
            return Maxheap.top();
        }
        else{
            return double(Maxheap.top()+Minheap.top())/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */