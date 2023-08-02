#include<bits/stdc++.h>
using namespace std;
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
  	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    // kruskal's algorithm
    void makeset(vector<int>& parent, vector<int>& rank, int n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int findparent(vector<int>& parent, int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findparent(parent, parent[node]);
    }
    void unionset(int u, int v, vector<int>& parent, vector<int>& rank) {
        u = findparent(parent, u);
        v = findparent(parent, v);
        if (rank[u] < rank[v]) {
            parent[u] = v;
        }
        else if (rank[v] < rank[u]) {
            parent[v] = u;
        }
        else {
            parent[v] = u;
            rank[u]++;
        }
    }
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }

    int spanningTree(int n, vector<vector<int>> ad[]) {
        vector<int> parent(n);
        vector<int> rank(n);
        makeset(parent, rank, n);

        vector<vector<int>> adj;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < ad[i].size(); j++) {
                int u = i;
                int v = ad[i][j][0];
                int w = ad[i][j][1];
                adj.push_back({ w, u, v });
            }
        }

        sort(adj.begin(), adj.end(), cmp);

        int minwt = 0;
        for (int i = 0; i < adj.size(); i++) {
            int u = findparent(parent, adj[i][1]);
            int v = findparent(parent, adj[i][2]);
            int wt = adj[i][0];
            if (u != v) {
                minwt += wt;
                unionset(u, v, parent, rank);
            }
    }return minwt;
}

int main() {
    int n = 4; // Number of nodes in the graph
    vector<vector<int>> ad[n];
    // Add edges and weights to the adjacency list
    // For example:
    ad[0].push_back({1, 5}); // Edge between node 0 and node 1 with weight 5
    ad[0].push_back({2, 3}); // Edge between node 0 and node 2 with weight 3
    ad[1].push_back({2, 2}); // Edge between node 1 and node 2 with weight 2
    ad[1].push_back({3, 6}); // Edge between node 1 and node 3 with weight 6
    ad[2].push_back({3, 4}); // Edge between node 2 and node 3 with weight 4

    int minWeight = spanningTree(n, ad);
    cout << "Minimum Weight of the Spanning Tree: " << minWeight << endl;

    return 0;
}
