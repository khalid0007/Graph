#include<bits/stdc++.h>
using namespace std;
#define lp(i, s, e) for(int i = s; i < e; i++)
#define eb emplace_back

const int M = 701, N = 1e5 + 1;


template<class __Type_L__, class __Type_R__> ostream& operator<<(ostream &os, pair<__Type_L__, __Type_R__> P) {
    return os << P.first << " " << P.second << "\n";
}

vector<pair<int, int>> g[N], ans;
int U[N], V[N], dis[N], fin[N], miniAncestor[N], tim;
bool isBridge[M], vis[N];

int dfs(int u, int parent = 0){
    vis[u] = true;
    dis[u] = tim++;

    for(auto it: g[u]){
        int v = it.first, indx = it.second;

        if(v == parent) continue; 
        else if(vis[v]) {
            miniAncestor[u] = min(miniAncestor[u], dis[v]);
        }
        else{
            dfs(v, u);
            miniAncestor[u] = min(miniAncestor[u], dis[v]);

            if(miniAncestor[v] > dis[u]){
                isBridge[indx] = 1;
                ans.emplace_back(U[indx], V[indx]);
            }
        }
    }
    fin[u] = tim;
}

int32_t main(){
    int t,n, m; cin >> t;

    lp(_case,1,t + 1){
        cin >> n >> m;
        tim = 0;
        lp(i,1,n+1) g[i].clear(), vis[i] = false;
        lp(i, 0, m){
            int u, v;
            cin >> u >> v;
            g[u].eb(v, i);
            g[v].eb(u, i);
            U[i] = u,V[i] = v;
            isBridge[i] = false;
            if(U[i] > V[i]) swap(U[i], V[i]);
        }

        ans.clear();

        dfs(1);

        cout << "Caso #" << _case << "\n";
        if(ans.size() == 0)  cout << "Sin bloqueos\n";
        else{
            sort(ans.begin(), ans.end());
            cout << ans.size() << "\n";
            for(auto x: ans) cout << x;
        }
    }
}