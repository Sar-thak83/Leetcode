class MedianFinder {
public:
    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int>> min;
    MedianFinder() {}

    void addNum(int num) {
        if (min.empty() || num < max.top()) {
            max.push(num);
        } else {
            min.push(num);
        }
        if (((int)max.size() - (int)min.size()) > 1) {
            min.push(max.top());
            max.pop();
        } else if (max.size() < min.size()) {
            max.push(min.top());
            min.pop();
        }
    }

    double findMedian() {
        if (min.size() == max.size()) {
            double mean = (min.top() + max.top()) / 2.0;
            return mean;
        }
        return max.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */