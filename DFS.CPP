#include<bits/stdc++.h>
using namespace std;
queue<int>q;
vector<int>ans;
void dfs(vector<vector<int>>&a,vector<int>& visited,int st){
ans.push_back(st);
visited[st]=1;
int n=a.size();
for(int i=0;i<n;i++){
    if(a[st][i]&& !visited[i]){
        dfs(a,visited,i);
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
