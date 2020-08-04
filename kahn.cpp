#include<bits/stdc++.h>
using namespace std;

// vector<int> g[N + 1] will represent the graph

vector<int>* topoSort(vector<int> g[], int n){
    vector<int> inDegree(n + 1, 0);

    for(int node = 1; node <= n; node++)
        for(auto& connectedNode : g[node]) 
            ++inDegree[connectedNode];

    queue<int> q;

    for(int node = 1; node <= n; node++)
        if(!inDegree[node]) q.push(node);

    vector<int>* ans = new vector<int>;
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        (*ans).push_back(x);

        for(auto& y: g[x])
            if(!(--inDegree[y])) q.push(y);
    }

    if((*ans).size() != n) {
        delete ans;
        return NULL;
    }

    else return ans;
}


int main(){

}