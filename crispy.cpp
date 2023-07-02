#include <iostream>
#include <vector>

using namespace std;

bool isValidCell(int i, int j, int rows, int cols, vector<vector<bool>>& visited) {
    return (i >= 0 && i < rows && j >= 0 && j < cols && !visited[i][j]);
}

bool dfs(vector<vector<char>>& grid, int i, int j, int index, vector<vector<bool>>& visited) {
    if (index == 11) {
        return true;  // Found the complete "CODINGNINJA" path
    }
    
    int rows = grid.size();
    int cols = grid[0].size();
    
    // Array to define the possible directions to move in the grid
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    visited[i][j] = true;
    
    for (int k = 0; k < 8; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        
        if (isValidCell(x, y, rows, cols, visited) && grid[x][y] == "CODINGNINJA"[index]) {
            if (dfs(grid, x, y, index + 1, visited)) {
                return true;  // Found a path in this direction
            }
        }
    }
    
    visited[i][j] = false;  // Reset visited status for backtracking
    
    return false;  // No path found in any direction
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<char>> grid(N, vector<char>(M));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }
    
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    
    bool pathExists = false;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 'C') {
                if (dfs(grid, i, j, 1, visited)) {
                    pathExists = true;
                    break;
                }
            }
        }
        
        if (pathExists) {
            break;
        }
    }
    
    if (pathExists) {
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }
    
    return 0;
}
