#include "146_LRU_cache.h"

namespace _146 {

    /*
    * The classic LRU Cache implementation.
    *
    * std::list — acts as an ordered queue where:
    *
    * Front = most recently used.
    * Back = least recently used.
    *
    * unordered_map<int, list::iterator> — maps each key to its node's iterator in the list, enabling O(1) random access.
    *
    * Time complexity:
    * O(1)
    *
    * Space complexity:
    * O(capacity)
    */
    LRUCache::LRUCache(int capacity) : capacity(capacity) {}

    int LRUCache::get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1;
        }

        auto it = cacheMap[key];
        CacheEntry entry = *it;
        cacheList.erase(it);
        cacheList.push_front(entry);
        cacheMap[key] = cacheList.begin();

        return entry.value;
    }

    void LRUCache::put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            // Key exists: update value and move the entry to the front (most recently used).
            auto it = cacheMap[key];
            it->value = value;
            cacheList.splice(cacheList.begin(), cacheList, it);
            cacheMap[key] = cacheList.begin();
        }
        else {
            // New key: insert at the front, evict LRU from the back.
            if (cacheList.size() == capacity) {
                int lastKey = cacheList.back().key;
                cacheMap.erase(lastKey);
                cacheList.pop_back();
            }

            cacheList.push_front({ key, value });
            cacheMap[key] = cacheList.begin();
        }
    }

}