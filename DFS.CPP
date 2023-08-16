#include<bits/stdc++.h>
using namespace std;
queue<int>q;
vector<int>ans;

void dfs(vector<vector<int>>& a, vector<int>& visited, int st) {
    stack<int> s;
    s.push(st); // Push the starting vertex onto the stack
    visited[st] = 1;
    int n = a.size();

    while (!s.empty()) {
        int top = s.top();
        ans.push_back(top);
        s.pop();

        for (int i = n - 1; i >= 0; i--) {
            if (a[top][i] && !visited[i]) {
                s.push(i);
                visited[i] = 1; // Mark the vertex as visited here
            }
        }
    }
}

int main(){
    cout<<"enter the number of vertices"<<endl;
    int n;
    cin>>n;
    vector<int>vis(n,0);
    vector<vector<int>>m(n,vector<int>(n));
    cout<<"enter the adjacency matrix";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>m[i][j];
        }
    } 
    cout<<"enter the start vertex"<<endl;
    int u;
    cin>>u;
    dfs(m,vis,u);
    for(auto x:ans){
        cout<<x;
    }
    return 0;
}
