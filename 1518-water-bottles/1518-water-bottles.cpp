class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int remaining = 0;
        while(numBottles != 0){
            ans += numBottles;
            remaining += numBottles % numExchange;
            numBottles /= numExchange;
            if(remaining >= numExchange){
                numBottles += remaining / numExchange;
                remaining %= numExchange;
            }
        }
        return ans; 
    }
};