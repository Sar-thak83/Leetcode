// class SeatManager {
// public:
//     priority_queue<int, vector<int>, greater<int>> pq;
//     SeatManager(int n) {
//         for (int i = 1; i <= n; i++)
//             pq.push(i);
//     }

//     int reserve() {
//         int seat = pq.top();
//         pq.pop();
//         return seat;
//     }

//     void unreserve(int seatNumber) { pq.push(seatNumber); }
// };




class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int seat_marker;
    SeatManager(int n) {
      seat_marker=1;
    }

    int reserve() {
        if(pq.empty())
        {
            return seat_marker++;
        }
        int seat = pq.top();
        pq.pop();
        return seat;
    }

    void unreserve(int seatNumber) { pq.push(seatNumber); }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */