

class Solution {
public:
    vector<vector<int>> t;
    vector<string> columnSt;
    const int MOD = 1e9 + 7;

    void generateColumnStates(string currentColumn, int rowsRemaining, char prevColor) {
        if (rowsRemaining == 0) {
            columnSt.push_back(currentColumn);
            return;
        }

        for (char color : {'K', 'G', 'B'}) {
            if (color == prevColor) 
                continue;  
            generateColumnStates(currentColumn + color, rowsRemaining - 1, color);
        }
    }

    int solve(int remainingCols, int prevColIdx,int m) {
        if (remainingCols == 0) 
            return 1;
        if (t[remainingCols][prevColIdx] != -1) 
            return t[remainingCols][prevColIdx];

        int totalWays = 0;
        string prevColumn = columnSt[prevColIdx];

        for (int nextColIdx = 0; nextColIdx < columnSt.size(); nextColIdx++) {
            string nextColumn = columnSt[nextColIdx];
            bool valid = true;

            for (int r = 0; r < 3; r++) {
                if (prevColumn[r] == nextColumn[r]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                totalWays = (totalWays + solve(remainingCols - 1, nextColIdx, 3)) % MOD;
            }
        }

        return t[remainingCols][prevColIdx] = totalWays;
    }

    int numOfWays(int n) {
        columnSt.clear();
        generateColumnStates("", 3, '#');  

        int numColumnPatterns = columnSt.size();
        t.assign(n, vector<int>(numColumnPatterns, -1));

        int result = 0;
        for (int i = 0; i < numColumnPatterns; i++) {
            result = (result + solve(n - 1, i, 3)) % MOD;
        }

        return result;
    }
};


