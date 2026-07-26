class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        if (n == 1)
            return 1;

        vector<vector<int>> dis(n, vector<int>(n, 1e9));

        queue<pair<int, pair<int,int>>> q;

        dis[0][0] = 1;
        q.push({1, {0, 0}});

        int dr[] = {-1,-1,-1,0,0,1,1,1};
        int dc[] = {-1,0,1,-1,1,-1,0,1};

        while (!q.empty()) {

            auto it = q.front();
            q.pop();

            int dist = it.first;
            int r = it.second.first;
            int c = it.second.second;

            for (int i = 0; i < 8; i++) {

                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < n &&
                    grid[nr][nc] == 0 &&
                    dist + 1 < dis[nr][nc]) {

                    dis[nr][nc] = dist + 1;

                    if (nr == n-1 && nc == n-1)
                        return dist + 1;

                    q.push({dist + 1, {nr, nc}});
                }
            }
        }

        return -1;
    }
};