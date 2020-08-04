#include<bits/stdc++.h>
using namespace std;


const int N = 1e5 + 1; //maximum vertices + 1
vector<int> g[N];

void dfs(int x = 1, int n) // x = root node and n = max vertices
{
    vector<bool> vis(n+1);

    queue<int> q; q.push(x);
    vis[x] = true;

    while(!q.empty()){
        x = q.front(); q.pop();

        for(auto adj: g[x]){
            if(vis[adj]) continue;
            else{
                vis[adj] = true;
                q.push(adj);
            }
        }
    }
}

int32_t main(){

    // if directed graph & a ---> b
    g[a].push_back(b);
    // if undirected graph a ---- b
    g[a].push_back(b);
    g[b].push_back(a);
}