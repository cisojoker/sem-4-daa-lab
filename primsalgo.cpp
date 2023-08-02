#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> min_tree(int n, vector<pair<pair<int, int>, int>> g) {
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < g.size(); i++) {
        int u = g[i].first.first;
        int w = g[i].second;
        int v = g[i].first.second;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> key(n + 1);
    vector<int> parent(n + 1);
    vector<bool> mst(n + 1);
    for (int k = 0; k <= n; k++) {
        key[k] = INT_MAX;
        parent[k] = -1;
        mst[k] = false;
    }

    key[1] = 0;
    parent[1] = -1;

    for (int i = 1; i < n; i++) {
        int mini = INT_MAX;
        int u;
        for (int t = 1; t <= n; t++) {
            if (mst[t] == false && key[t] < mini) {
                u = t;
                mini = key[u];
            }
        }

        mst[u] = true;
        for (auto it : adj[u]) {
            int v = it.first;
            int w = it.second;
            if (mst[v] == false && w < key[v]) {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;
    for (int i = 2; i <= n; i++) {
        result.push_back({{parent[i], i}, key[i]});
    }

    return result;
}

int main() {
    // Example usage:
    int n = 5;
    vector<pair<pair<int, int>, int>> g = {
        {{1, 2}, 3},
        {{1, 3}, 2},
        {{2, 3}, 1},
        {{2, 4}, 5},
        {{3, 4}, 4},
        {{3, 5}, 6},
        {{4, 5}, 7}
    };

    vector<pair<pair<int, int>, int>> result = min_tree(n, g);

    for (auto edge : result) {
        cout << edge.first.first << " - " << edge.first.second << " : " << edge.second << endl;
    }

    return 0;
}
