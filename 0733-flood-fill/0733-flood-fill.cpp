// class Solution {
// public:
//     bool isValid(vector<vector<int>>& image, int i, int j, int n, int m,
//                  int rang) {
//         if (i >= 0 && j >= 0 && j < m && j < n && image[i][j] == rang)
//             return true;
//         return false;
//     }
//     void floodfill(vector<vector<int>>& image, int sr, int sc, int n, int m,
//                    int newColor, int color) {
//         image[sr][sc] = newColor;
//         if (isValid(image, sr + 1, sc, n, m, color))
//             floodfill(image, sr + 1, sc, n, m, newColor, color);
//         if (isValid(image, sr - 1, sc, n, m, color))
//             floodfill(image, sr - 1, sc, n, m, newColor, color);
//         if (isValid(image, sr, sc + 1, n, m, color))
//             floodfill(image, sr, sc + 1, n, m,  newColor, color);
//         if (isValid(image, sr, sc - 1, n, m, color))
//             floodfill(image, sr, sc + 1, n, m,  newColor, color);
//     }
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
//                                   int color) {
//         int n = image.size();
//         int m = image[0].size();
//         int rang = image[sr][sc];

//         floodfill(image, sr, sc, n, m, color, rang);
//         return image;
//     }
// };
class Solution {
public:
    // Helper function to check if the pixel is valid for filling
    bool isValid(vector<vector<int>>& image, int i, int j, int n, int m, int rang) {
        return (i >= 0 && i < n && j >= 0 && j < m && image[i][j] == rang);
    }

    // Recursive flood fill function
    void floodfill(vector<vector<int>>& image, int sr, int sc, int n, int m, int newColor, int oldColor) {
        // Change the current pixel's color
        image[sr][sc] = newColor;

        // Check and fill the four neighboring pixels
        if (isValid(image, sr + 1, sc, n, m, oldColor))
            floodfill(image, sr + 1, sc, n, m, newColor, oldColor);
        if (isValid(image, sr - 1, sc, n, m, oldColor))
            floodfill(image, sr - 1, sc, n, m, newColor, oldColor);
        if (isValid(image, sr, sc + 1, n, m, oldColor))
            floodfill(image, sr, sc + 1, n, m, newColor, oldColor);
        if (isValid(image, sr, sc - 1, n, m, oldColor))
            floodfill(image, sr, sc - 1, n, m, newColor, oldColor);
    }

    // Main function to initiate the flood fill
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        int oldColor = image[sr][sc];

        // If the new color is the same as the old color, no need to do anything
        if (oldColor != newColor) {
            floodfill(image, sr, sc, n, m, newColor, oldColor);
        }

        return image;
    }
};
