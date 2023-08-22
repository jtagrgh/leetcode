// https://leetcode.com/problems/flood-fill

class Solution {
public:
    void fill (vector<vector<int>>& image, int a, int b, int color, int ic) {
        if (image[a][b] == ic) {
            image[a][b] = color;
            if (a > 0 && image[a-1][b] == ic) fill(image, a-1, b, color, ic);
            if (a < image.size()-1 && image[a+1][b] == ic) fill(image, a+1, b, color, ic);
            if (b > 0 && image[a][b-1] == ic) fill(image, a, b-1, color, ic);
            if (b < image[0].size()-1 && image[a][b+1] == ic) fill(image, a, b+1, color, ic);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ic = image[sr][sc];
        if (ic != color) fill(image, sr, sc, color, ic);
        return image;
    }
};