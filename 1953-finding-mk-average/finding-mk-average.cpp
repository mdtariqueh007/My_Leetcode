class MKAverage {
    private:
    deque<int> dq;
    multiset<int> low, mid, high;
    int M, K;
    long long midSum = 0;
public:
    MKAverage(int m, int k) {

        M = m;
        K = k;
        
    }
    
    void addElement(int num) {

        if(dq.size()==M){
            int val = dq.front();
            dq.pop_front();
            
            if(low.count(val)){
                low.erase(low.find(val));
            }
            else if(mid.count(val)){
                mid.erase(mid.find(val));
                midSum -= val;
            }
            else{
                high.erase(high.find(val));
            }
        }

        dq.push_back(num);
        
        if(!mid.empty() && num>=*mid.begin()){
            mid.insert(num);
            midSum += num;
        }
        else{
            low.insert(num);
        }

        if(low.size()>K){
            auto it = prev(low.end());
            mid.insert(*it);
            midSum += *it;
            low.erase(it);
        }
        if(mid.size()>M - 2*K){
            if(high.size()<K){
                auto it = prev(mid.end());
                high.insert(*it);
                midSum -= *it;
                mid.erase(it);
            }
            else if(low.size()<K){
                auto it = mid.begin();
                low.insert(*it);
                midSum -= *it;
                mid.erase(it);
            }
        }

        if(mid.size()>0 && low.size()>0 && *mid.begin()<*prev(low.end())){
            auto it1 = mid.begin();
            auto it2 = prev(low.end());

            mid.insert(*it2);
            midSum += *it2;
            low.erase(it2);
            midSum -= *it1;
            low.insert(*it1);
            mid.erase(it1);
        }

        if(mid.size()>0 && high.size()>0 && *prev(mid.end())>*high.begin()){

            auto it1 = prev(mid.end());
            auto it2 = high.begin();

            high.insert(*it1);
            midSum -= *it1;
            mid.erase(it1);
            midSum += *it2;
            mid.insert(*it2);
            high.erase(it2);

        }
        
        
    }
    
    int calculateMKAverage() {

        if(dq.size() < M){
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