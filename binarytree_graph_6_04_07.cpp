#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Функция BFS для обхода острова
void bfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
    int n = grid.size();
    int m = grid[0].size();

    vector<pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    queue<pair<int, int>> q;
    q.push({ i, j });
    visited[i][j] = true;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;

        for (auto dir : directions) {
            int nx = x + dir.first;
            int ny = y + dir.second;

            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                grid[nx][ny] == 1 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({ nx, ny });
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter amount of rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    cout << "Enter the matrix where 1 is island and 0 is watew\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> grid[i][j];

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int islandCount = 0;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (grid[i][j] == 1 && !visited[i][j]) {
                bfs(i, j, grid, visited);
                ++islandCount;
            }

    cout << "Amount of islands: " << islandCount << endl;

    return 0;
}
