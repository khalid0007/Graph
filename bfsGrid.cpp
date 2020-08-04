#include<bits/stdc++.h>

using namespace std;

const int N  = 3e3 + 2; // N = max length  + 2
bool grid[N][N], vis[N][N]; // grid[i][j] = 1 means it can be accesable

void bfs(int x, int y){
    vis[x][y] = true;
    int ds[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

    queue<pair<int, int>> q;q.push({x, y});

    while(!q.empty()){
        auto t = q.front(); q.pop();

        x = t.first, y = t.second;

        for(int dir = 0; dir < 4; dir++){
            int xx = x + dx[dir], yy = y + dy[dir];
            if(grid[xx][yy] && !vis[xx][yy]){
                vis[xx][yy] = true;
                q.push({xx, yy});
            }
        }
    }
}



int32_t main() {

}