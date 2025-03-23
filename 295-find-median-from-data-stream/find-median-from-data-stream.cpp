class MedianFinder {
    private:
    multiset<int> low, high;
public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(low.empty() || num<=*low.rbegin()){
            low.insert(num);
        }
        else{
            high.insert(num);
        }

        if(low.size()>high.size()){
            int x = *low.rbegin();
            low.erase(prev(low.end()));
            high.insert(x);
        }

        if(high.size()>low.size() + 1){
            int x = *high.begin();
            high.erase(high.begin());
            low.insert(x);
        }

        if(low.size() && high.size() && *low.rbegin()>*high.begin()){
            int x1 = *low.rbegin();
            int x2 = *high.begin();

            low.erase(prev(low.end()));
            high.erase(high.begin());

            low.insert(x2);
            high.insert(x1);
        } 
    }
    
    double findMedian() {
        double median;
        if(low.size()<high.size()){
            median = *high.begin();
        }
        else{
            median = (*high.begin()*1.0 + *low.rbegin()*1.0)*1.0/2.0;
        }
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */