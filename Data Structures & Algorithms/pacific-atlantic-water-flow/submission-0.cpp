class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int columns = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool> (columns, false));

        vector<vector<bool>> atlantic(rows, vector<bool> (columns, false));

        // Top and bottom borders
        for (int col = 0; col < columns; col++) {
            dfs(0, col, heights, pacific);          // Pacific
            dfs(rows - 1, col, heights, atlantic); // Atlantic
        }

        // Left and right borders
        for (int row = 0; row < rows; row++) {
            dfs(row, 0, heights, pacific);          // Pacific
            dfs(row, columns - 1, heights, atlantic); // Atlantic
        }

        vector<vector<int>> result;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < columns; col++) {
                if (pacific[row][col] && atlantic[row][col]) {
                    result.push_back({row, col});
                }
            }
        }

        return result;


    }
private:
    void dfs(
        int row,
        int col,
        vector<vector<int>>& heights,
        vector<vector<bool>>& visited
    ) {
        visited[row][col] = true;

        int rows = heights.size();
        int columns = heights[0].size();

        int directions[4][2] = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        for (auto& direction : directions) {
            int nextRow = row + direction[0];
            int nextCol = col + direction[1];

            if (
                nextRow < 0 || nextRow >= rows ||
                nextCol < 0 || nextCol >= columns
            ) {
                continue;
            }

            if (visited[nextRow][nextCol]) {
                continue;
            }

            // Reverse water flow: move uphill or across equal height
            if (heights[nextRow][nextCol] >= heights[row][col]) {
                dfs(nextRow, nextCol, heights, visited);
            }
        }
    }
};
