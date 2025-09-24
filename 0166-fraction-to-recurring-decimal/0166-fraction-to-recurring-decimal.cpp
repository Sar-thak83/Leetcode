class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string result = "";
        if ((numerator > 0) ^ (denominator > 0)) {
            result += "-";
        }
        long long num = abs((long long)numerator);
        long long den = abs((long long)denominator);
        result += to_string(num / den);
        num %= den;
        if (num == 0) return result;
        result += ".";
        unordered_map<long long, int> map;
        while (num != 0) {
            if (map.count(num)) {
                int index = map[num];
                result.insert(index, "(");
                result += ")";
                break;
            }
            
            map[num] = result.length();
            num *= 10;
            result += to_string(num / den);
            num %= den;
        }
        return result;
    }
};