// class Solution {
// public:
//     vector<int> spiralOrder(vector<vector<int>>& matrix) {
//         vector<int> ans;
//         if (matrix.empty()) return ans;
//         int count = 0;
//         int row = matrix.size();
//         int coloum = matrix[0].size();
//         int start_coloum = 0;
//         int start_row = 0;
//         int end_coloum = coloum - 1;
//         int end_row = row - 1;
//         int total = row * coloum;
//         while (count < total) {
//             for (int index = start_coloum; count < total && index <= end_coloum;
//                  index++) {
//                 ans.push_back(matrix[start_row][index]);
//                 count++;
//             }
//             start_row++;
//             for (int index = start_row; count < total && index <= end_row;
//                  index++) {
//                 ans.push_back(matrix[index][end_coloum]);
//                 count++;
//             }
//             end_coloum--;
//             for (int index = end_coloum; count < total && index >= start_coloum;
//                  index--) {
//                 ans.push_back(matrix[end_row][index]);
//                 count++;
//             }
//             end_row--;
//             for (int index = end_row; count < total && index >= start_row;
//                  index++) {
//                 ans.push_back(matrix[index][start_coloum]);
//                 count++;
//             }
//             start_coloum++;
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty()) return ans;  
        
        int count = 0;
        int row = matrix.size();
        int column = matrix[0].size();  // Corrected spelling from "coloum" to "column"
        int start_column = 0;
        int start_row = 0;
        int end_column = column - 1;  // Corrected spelling from "coloum" to "column"
        int end_row = row - 1;
        int total = row * column;

        while (count < total) {
            for (int index = start_column; count < total && index <= end_column; index++) {
                ans.push_back(matrix[start_row][index]);
                count++;
            }
            start_row++;
            for (int index = start_row; count < total && index <= end_row; index++) {
                ans.push_back(matrix[index][end_column]);
                count++;
            }
            end_column--;
            for (int index = end_column; count < total && index >= start_column; index--) {
                ans.push_back(matrix[end_row][index]);
                count++;
            }
            end_row--;
            for (int index = end_row; count < total && index >= start_row; index--) {
                ans.push_back(matrix[index][start_column]);
                count++;
            }
            start_column++;
        }
        return ans;
    }
};


