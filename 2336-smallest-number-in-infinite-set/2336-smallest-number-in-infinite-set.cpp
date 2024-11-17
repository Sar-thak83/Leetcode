class SmallestInfiniteSet {
public:
    set<int> st;
    int next;
    SmallestInfiniteSet() { next = 1; }
    int popSmallest() {
        if (!st.empty()) {
            int top = *st.begin();
            st.erase(top);
            return top;
        }
        return next++;
    }
    void addBack(int num) {
        if (num >= next || st.find(num) != st.end()) {
            return;
        }
        st.insert(num);
    }
};

// ------------------Better Appproach -2----------------

// class SmallestInfiniteSet {
// public:
//     priority_queue<int, vector<int>, greater<int>> pq;
//     unordered_set<int> st;
//     int next;
//     SmallestInfiniteSet() { next = 1; }
//     int popSmallest() {
//         if (pq.empty()) {
//             return next++;
//         }
//         int top = pq.top();
//         pq.pop();
//         st.erase(top);
//         return top;
//     }
//     void addBack(int num) {
//         if (num >= next || st.find(num) != st.end()) {
//             return;
//         }
//         pq.push(num);
//         st.insert(num);
//     }
// };

// -------------------Basic Approach - 1-------------------------------------

// class SmallestInfiniteSet {
// public:
//     vector<bool> nums(1001, true);
//     int i;
//     SmallestInfiniteSet() { i = 1; }

//     int popSmallest() {
//         int result = i;
//         nums[i] = false;
//         for (int j = i + 1; j < 1001; j++) {
//             if (nums[j] == true) {
//                 i = j;
//                 break;
//             }
//         }
//     }

//     void addBack(int num) {
//         nums[num] = true;
//         if (num < i) {
//             i = num;
//         }
//     }
// };

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */