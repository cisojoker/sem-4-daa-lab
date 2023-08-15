#include <bits/stdc++.h>
using namespace std;
bool cmp(vector<int>&a ,vector<int>&b){
    return b[0]>a[0];
}

int findparent(vector<int >&parent,int node){
    if(parent[node]==node){
        return node;
    }
    return parent[node]=findparent(parent,parent[node]);
}
void unionset(vector<int>&rank,vector<int>& parent,int u,int v){
    int p=findparent(parent,u);
    int o=findparent(parent,v);
    if(rank[p]>rank[o]){
        parent[o]=p;
    }
    else if (rank[p]<rank[o]){
        parent[p]=o;
    }
    else{
        parent[p]=o;
        rank[o]++;
    }
}
int spanningtree(vector<vector<vector<int>>> adj,int v){
    vector<int>parent(v);
    vector<int>rank(v);
    for(int i=0;i<v;i++){
        parent[i]=i;
        rank[i]=0;
    }
    vector<vector<int>>ad;
    for(int i=0;i<v;i++){
        for(int j=0;j<adj[i].size();j++){
            int u=i;
            int v=adj[i][j][0];
            int w=adj[i][j][1];
          ad.push_back({w,u,v});
        }
    }
    sort(ad.begin(),ad.end(),cmp);
    int wt=0;
    for(int u=0;u<ad.size();u++){
        int x=findparent(parent,ad[u][1]);
        int y=findparent(parent,ad[u][2]);
        if(x!=y){
            wt+=ad[u][0];
            unionset(rank,parent,x,y);
        }
    }
    return wt;
}
int main(){
    cout<<"enter the number of vertices and edges";
    int v,e;
    cin>>v>>e;
    vector<vector<vector<int>>>adj(v);
    for(int i=0;i<e;i++){
        int from,to,wt;
        cin>>from>>to>>wt;
        adj[from].push_back({to,wt});
    }
    cout<<spanningtree(adj,v);
    return 0;
}
