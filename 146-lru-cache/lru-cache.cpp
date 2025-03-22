class LRUCache {
    private:
    int cap;
    list<pair<int,int>> dll;
    unordered_map<int, list<pair<int,int>>::iterator> cache;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {

        if(cache.find(key)==cache.end()){
            return -1;
        }

        auto it = cache[key];
        pair<int,int> item = *it;
        dll.erase(it);
        dll.push_front(item);
        cache[key] = dll.begin();
        return item.second;
        
    }
    
    void put(int key, int value) {

        if(cache.find(key)!=cache.end()){
            auto it = cache[key];
            dll.erase(it);
            dll.push_front({key, value});
            cache[key] = dll.begin();
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