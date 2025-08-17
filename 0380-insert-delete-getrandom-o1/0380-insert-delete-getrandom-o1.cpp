class RandomizedSet {
public:
    set<int> st;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(st.find(val) == st.end()) {
            st.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(st.find(val) == st.end())return false;
        st.erase(val);
        return true;
    }
    
    int getRandom() {
        return *next(st.begin(),rand()%st.size());
    }
};