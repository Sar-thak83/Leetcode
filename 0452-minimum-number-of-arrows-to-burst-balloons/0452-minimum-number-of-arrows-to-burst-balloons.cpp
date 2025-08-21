#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int arrows = 1;
        int arrowPos = points[0][1];

        for (const auto& balloon : points) {
            if (balloon[0] > arrowPos) {
                arrows++;
                arrowPos = balloon[1];
            }
        }
        return arrows;
    }
};
