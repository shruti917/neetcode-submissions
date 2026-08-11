class LRUCache {
   public:
   int capacity;
   list<pair<int,int>>lru;
   unordered_map<int,list<pair<int,int>>::iterator>mp;

    LRUCache(int capacity) {
        this->capacity= capacity;
    }


    int get(int key) {
        if(mp.find(key)==mp.end())return -1;
        
        auto it= mp[key];
        int value= it->second;
        lru.erase(it);
        lru.push_back({key,value});
        mp[key]= --lru.end();
        return value;
        
    }

    void put(int key, int value) {


        if(mp.find(key)!=mp.end()){
        auto it= mp[key];
      
        lru.erase(it);
        lru.push_back({key,value});
        mp[key]= --lru.end();
        return;
        }


        if(lru.size()== capacity){
            int k= lru.front().first;
            mp.erase(k);
            lru.pop_front();
        }

                lru.push_back({key, value});

        mp[key] =--lru.end();
    }
};
