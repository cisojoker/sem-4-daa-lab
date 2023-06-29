#include <bits/stdc++.h>
using namespace std;

queue<int> q;
vector<int> ans;

void bfs(int st, vector<vector<int>>& a, vector<int>& ans, vector<int>& visited) {
    q.push(st);
    visited[st] = 1;
    ans.push_back(st);
    int n = visited.size();
    while (!q.empty()) {
        int ft = q.front();
        q.pop();
        for (int i = 0; i < n; i++) {
            if (a[ft][i] && !visited[i]) {
                q.push(i);
                visited[i] = 1;
                ans.push_back(i);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    vector<int> visited(n, 0);

    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int st;
    cout << "Enter the start vertex: ";
    cin >> st;

    bfs(st, a, ans, visited);

    cout << "The traversed path is:" << endl;
    for (auto x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}
