class Solution {
public:
    typedef pair < double, pair<int, int>> p;
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<p, vector<p>> pq;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                double sum =(double) arr[i] / arr[j];
                if (pq.size() < k) {
                    pq.push({sum, {i,j}});
                } else if (pq.top().first > sum) {
                    pq.pop();
                    pq.push({sum, {i,j}});
                }
            }
        }
        auto temp=pq.top();
        int i=temp.second.first;
        int j=temp.second.second;
        return {arr[i],arr[j]};
    }
};


