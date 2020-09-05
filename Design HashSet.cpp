class MyHashSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int, int> umap;
    MyHashSet() {
        
    }
    
    void add(int key) {
        umap[key] = 1;
    }
    
    void remove(int key) {
        if(umap.find(key) != umap.end())
            umap.erase(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        if(umap.find(key) != umap.end())
            return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
