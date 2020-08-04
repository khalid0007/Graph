#include<bits/stdc++.h>
using namespace std;


const int N = 1e5 + 1; //maximum vertices + 1
vector<int> g[N];

void dfs_util(int x, vector<bool>& vis){
    vis[x] = true;
    for(auto adj: g[x])
        if(vis[adj]) continue;
        else dfs_util(adj, vis);
}

void dfs(int n) // x = root node and n = max vertices
{
    vector<bool> vis(n+1);

    for(int i = 1; i <= n; i++){
        if(vis[i]) continue;
        else dfs_util(i, vis);
    }
}

int32_t main(){

    // if directed graph & a ---> b
    g[a].push_back(b);
    // if undirected graph a ---- b
    g[a].push_back(b);
    g[b].push_back(a);
}