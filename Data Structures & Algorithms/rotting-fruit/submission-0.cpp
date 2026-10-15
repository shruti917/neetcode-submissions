
class Solution {
public:
    vector<pair<int, int>> dist = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };

    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;
        int t = 0;

        // Add all rotten oranges to the queue.
        // Count all fresh oranges.
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        // Process one level per minute.
        while (!q.empty() && fresh > 0) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (auto [dr, dc] : dist) {
                    int nr = r + dr;
                    int nc = c + dc;

                    if (nr < 0 || nc < 0 ||
                        nr >= row || nc >= col ||
                        grid[nr][nc] != 1) {
                        continue;
                    }

                    grid[nr][nc] = 2;
                    fresh--;
                    q.push({nr, nc});
                }
            }

            t++;
        }

        return fresh == 0 ? t : -1;
    }
};
