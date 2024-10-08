class MyCalendar {
    private:
    vector<pair<int,int>> events;
public:
    MyCalendar() {

        
        
    }
    
    bool book(int start, int end) {

        for(const auto [s,e] : events){
            if(end>s && e>start){
                return false;
            }
        }

        events.push_back({start,end});

        return true;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */