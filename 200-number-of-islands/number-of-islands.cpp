class Solution {
public:
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int row, int col) {
        vis[row][col] = 1;

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {

                if (abs(i) + abs(j) != 1) continue;

                int newRow = row + i;
                int newCol = col + j;

                if (newRow >= 0 && newRow < grid.size() &&
                    newCol >= 0 && newCol < grid[0].size() &&
                    vis[newRow][newCol] == 0 &&
                    grid[newRow][newCol] == '1') {

                    bfs(grid, vis, newRow, newCol);
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0 && grid[i][j] == '1') {
                    bfs(grid, vis, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};