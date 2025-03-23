class MKAverage {
    private:
    int M, K;
    long long midSum = 0;
    deque<int> dq;
    multiset<int> low, mid, high;
public:
    MKAverage(int m, int k) {

        M = m;
        K = k;
        
    }
    
    void addElement(int num) {

        if(low.empty() || num<=*low.rbegin()){
            low.insert(num);
        }
        else if(high.empty() || num>=*high.begin()){
            high.insert(num);
        }
        else{
            mid.insert(num);
            midSum += num;
        }

        dq.push_back(num);

        if(dq.size()>M){
            int val = dq.front();
            dq.pop_front();

            if(low.count(val)){
                low.erase(low.find(val));
            }
            else if(high.count(val)){
                high.erase(high.find(val));
            }
            else{
                mid.erase(mid.find(val));
                midSum -= val;
            }

        }

        while(low.size()>K){
            int x = *low.rbegin();
            low.erase(prev(low.end()));
            mid.insert(x);
            midSum += x;
        }

        while(high.size()>K){
            int x = *high.begin();
            high.erase(high.begin());
            mid.insert(x);
            midSum += x;
        }

        while(low.size()<K && mid.size()){
            int x = *mid.begin();
            low.insert(x);
            mid.erase(mid.begin());
            midSum -= x;
        }

        while(high.size()<K && mid.size()){
            int x = *mid.rbegin();
            high.insert(x);
            mid.erase(prev(mid.end()));
            midSum -= x;
        }
        
    }
    
    int calculateMKAverage() {

        if(dq.size()<M){
            return -1;
        }

        int avg = midSum/(M - 2 * K);

        return avg;
        
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */