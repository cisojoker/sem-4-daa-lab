#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(vector<vector<int>>& a, vector<int>& ans, stack<int>& m, vector<int>& visited) {
    cout << "Enter the vertex to start: ";
    int st;
    cin >> st;
    m.push(st);
    while (!m.empty()) {
        int top = m.top();
        ans.push_back(top);
        visited[top] = 1;
        m.pop();
        for (int k = a[top].size() - 1; k >= 0; k--) {
            if (a[top][k] == 1 && visited[k] == 0) {
                m.push(k);
                visited[k] = 1;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    vector<int> visited(n, 0);
    cout << "Enter the number of edges: ";
    int o;
    cin >> o;
    stack<int> m;
    vector<vector<int>> a(n, vector<int>(n, 0));
    cout << "Enter the edges: " << endl;
    for (int j = 0; j < o; j++) {
        int v, c;
        cin >> v >> c;
        a[v][c] = 1;
    }
    vector<int> ans;
    dfs(a, ans, m, visited);
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
