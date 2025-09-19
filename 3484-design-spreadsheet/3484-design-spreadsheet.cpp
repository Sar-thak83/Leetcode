class Spreadsheet {
    unordered_map<string, int> cells;
    int rows;
    bool isNumber(const string& s) {
        if (s.empty())
            return false;
        int i = 0;
        if (s[0] == '-')
            i = 1;
        for (; i < s.size(); i++)
            if (!isdigit(s[i]))
                return false;
        return true;
    }
    int evaluateFormula(const string& formula) {
        string token;
        int result = 0, sign = 1;
        for (int i = 0; i <= formula.size(); i++) {
            if (i < formula.size() &&
                (isalnum(formula[i]) || formula[i] == '-')) {
                token += formula[i];
            } else {
                if (!token.empty()) {
                    if (isNumber(token))
                        result += sign * stoi(token);
                    else
                        result +=
                            sign * (cells.count(token) ? cells[token] : 0);
                    token.clear();
                }
                if (i < formula.size() && formula[i] == '-')
                    sign = -1;
                else
                    sign = 1;
            }
        }
        return result;
    }

public:
    Spreadsheet(int r) { rows = r; }
    void setCell(string cell, int value) { cells[cell] = value; }
    void resetCell(string cell) { cells.erase(cell); }
    int getValue(string formula) { return evaluateFormula(formula); }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */