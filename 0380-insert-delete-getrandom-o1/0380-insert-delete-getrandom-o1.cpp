#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
private:
    vector<int> nums;                  
    unordered_map<int, int> idx;       

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (idx.find(val) != idx.end()) return false; 
        nums.push_back(val);                
        idx[val] = nums.size() - 1;         
        return true;
    }

    bool remove(int val) {
        if (idx.find(val) == idx.end()) return false; 
        int last = nums.back();             
        int pos = idx[val];                 
        nums[pos] = last;                   
        idx[last] = pos;                    
        nums.pop_back();                    
        idx.erase(val);                     
        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }
};
