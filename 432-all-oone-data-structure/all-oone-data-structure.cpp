class AllOne {
    private:
    unordered_map<string,int> mp;
    set<pair<int,string>> st;
public:
    AllOne() {
        
        mp.clear();
        
    }
    
    void inc(string key) {
        int cnt = mp[key];
        mp[key]++;
        st.erase({cnt,key});
        st.insert({cnt+1,key});
    }
    
    void dec(string key) {

        int cnt = mp[key];
        mp[key]--;
        st.erase({cnt,key});

        if(mp[key]>0){
            st.insert({cnt-1,key});
        }
        else{
            mp.erase(key);
        }
        
    }
    
    string getMaxKey() {

        if(!st.empty()){
            return st.rbegin()->second;
        }

        return "";
        
    }
    
    string getMinKey() {

        if(!st.empty()){
            return st.begin()->second;
        }

        return "";
        
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */