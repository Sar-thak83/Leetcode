class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // int n=gas.size();
        // for(int j=0;j<n;j++){
        //     int tank =0;
        //     bool complete =true;
        //     for(int i=0;i<n;i++){
        //         int station=(i+j)%n;
        //         tank+=gas[station]-cost[station];
        //         if (tank < 0) {
        //             complete = false;
        //             break;
        //         }
        //     }
        //     if (complete) {
        //         return j;
        //     }
        // } 
        // return -1;


        int totalTank = 0;   
        int currTank = 0;    
        int startStation = 0;
        for (int i = 0; i < gas.size(); i++) {
            int netGas = gas[i] - cost[i];
            totalTank += netGas;
            currTank += netGas;
            
            if (currTank < 0) {
                startStation = i + 1;
                currTank = 0;
            }
        }
        return totalTank >= 0 ? startStation : -1;
    }
};