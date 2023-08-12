#include <bits/stdc++.h>

using namespace std;

int tsp(const vector<vector<int>>& cost) {
    int n = cost.size();
    vector<int> tour(n, 0);  // Initialize tour with city indices
    for (int i = 1; i < n; ++i) {
        tour[i] = i;
    }
    int min_cost = INT_MAX;
    do {
        int current_cost = 0;
        int current_city = 0;

        for (int i = 0; i < n; ++i) {
            current_cost += cost[current_city][tour[i]];
            current_city = tour[i];
        }
        current_cost += cost[current_city][0];  // Return to city 0
        min_cost = min(min_cost, current_cost);
    } while (next_permutation(tour.begin() + 1, tour.end()));
    return min_cost;
}
int main()
{ 
    vector<vector<int>> cost = {
    {0, 1000,5000},
    {5000, 0, 1000},
    {1000,5000, 0}
} ;
cout<<tsp(cost);
    return 0;
}
