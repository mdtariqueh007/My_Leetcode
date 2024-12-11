class MyCalendarTwo {
    private:
    map<int,int> line;
public:
    MyCalendarTwo() {
        line.clear();
    }
    
    bool book(int startTime, int endTime) {
        line[startTime]++;
        line[endTime]--;

        int cnt = 0;

        for(auto it: line){
            cnt += it.second;

            if(cnt==3){
                line[startTime]--;
                line[endTime]++;

                return false;
            }
        }

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */