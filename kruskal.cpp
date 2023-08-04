#include<bits/stdc++.h>
using namespace std;
static bool cmp(vector<int>&a,vector<int>& b){
	    return b[0]>a[0];
	}
	void makeset(vector<int>&parent,vector<int>&rank,int V){
	    for (int i=0;i<V;i++){
	        parent[i]=i;
	        rank[i]=0;
	    }
	}
	int findparent(vector<int>& parent,int node){
	    if (parent[node]==node){
	        return node;
	    }
	    return parent[node]=findparent(parent,parent[node]);
	}
	void unionset(vector<int>&parent,vector<int>&rank,int u,int v){
	    int f=findparent(parent,u);
	    int s=findparent(parent,v);
	    if (rank[f]<rank[s]){
	        parent[f]=s;
	    }
	    else if(rank[s]<rank[f]){
	        parent[s]=f;
	    }
	    else{
	         parent[s]=f;
	         rank[f]++;
	    }
	}
    int spanningTree(int V, vector<vector<vector<int>>>adj)
    {
       vector<int>parent(V);
       vector<int>rank(V);
       makeset(parent,rank,V);
       
       vector<vector<int>>ad;
       for (int j=0;j<V;j++){
           for(int  o=0;o<adj[j].size();o++){
               int v=adj[j][o][0];
               int w=adj[j][o][1];
               int u=j;
               ad.push_back({w,u,v});
           }
       }
       sort(ad.begin(),ad.end(),cmp);
       int wt=0;
       for(int i=0;i<ad.size();i++){
           int u=findparent(parent,ad[i][1]);
           int v=findparent(parent,ad[i][2]);
           if(u!=v){
               wt=wt+ad[i][0];
               unionset(parent,rank,u,v);
           }
       }
       return wt;
    }
    int main() {
    int n = 4; // Number of nodes in the graph
    vector<vector<vector<int>>> ad(n);
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
