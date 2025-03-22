class LRUCache {
    private:
    int cap;
    list<pair<int,int>> dll;
    unordered_map<int, list<pair<int,int>>::iterator> cache;
    void makeMostRecentlyUsed(int key, int value){
        
        dll.erase(cache[key]);
        dll.push_front({key, value});
        cache[key] = dll.begin();
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {

        if(cache.find(key)==cache.end()){
            return -1;
        }

        pair<int,int> it = *(cache[key]);

        
        makeMostRecentlyUsed(key, it.second);
        
        return it.second;
        
    }
    
    void put(int key, int value) {

        if(cache.find(key)!=cache.end()){
            makeMostRecentlyUsed(key, value);
            return;
        }

        if(dll.size()==cap){
            int key = dll.back().first;
            cache.erase(key);
            dll.pop_back();
        }

        dll.push_front({key, value});
        cache[key] = dll.begin();
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */