// class Solution {
// public:
//     int romanToInt(string s) {
//         unordered_map<char, int> m;
        
//         m['I'] = 1;
//         m['V'] = 5;
//         m['X'] = 10;
//         m['L'] = 50;
//         m['C'] = 100;
//         m['D'] = 500;
//         m['M'] = 1000;
        
//         int ans = 0;
        
//         for(int i = 0; i < s.length(); i++){
//             if(m[s[i]] < m[s[i+1]]){
//                 ans -= m[s[i]];
//             }
//             else{
//                 ans += m[s[i]];
//             }
//         }
//         return ans;
//     }
// };  
    class Solution {
public:
    int romanToInt(string s) {
        vector<int> v;   
        for(char c : s){
            if (c =='I') v.push_back(1);
            else if (c == 'V') v.push_back(5);
            else if (c == 'X') v.push_back(10);
            else if (c == 'L') v.push_back(50);
            else if (c == 'C') v.push_back(100);
            else if (c == 'D') v.push_back(500);
            else v.push_back(1000);
        }
        int sum = 0;
       for(int i = 0; i < v.size()- 1; i++){
            if( v[i] >= v[i+1]) sum += v[i];
            else sum -= v[i];
        }
        sum += v[v.size() - 1];
        return sum;   
    }
};