class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color,
             vector<vector<int>>& ans, int initialColor) {

        ans[sr][sc] = color;

        int n = image.size();
        int m = image[0].size();

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int newRow = sr + delRow[i];
            int newCol = sc + delCol[i];

            if (newRow >= 0 && newRow < n &&
                newCol >= 0 && newCol < m &&
                ans[newRow][newCol] != color &&
                image[newRow][newCol] == initialColor) {

                dfs(image, newRow, newCol, color, ans, initialColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int initialColor = image[sr][sc];

        vector<vector<int>> ans = image;

        if (initialColor == color)
            return ans;

        dfs(image, sr, sc, color, ans, initialColor);

        return ans;
    }
};