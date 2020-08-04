#include<bits/stdc++.h>

using namespace std;

class Graph{
    int v;
    list<int> *adj;

    void topologicalSortUtil(int vi, vector<bool>& visited, stack<int> &Stack){
        visited[vi] = true;

        for(auto i: adj[vi]) 
            if(visited[i] == false) topologicalSortUtil(i, visited, Stack);


        Stack.push(vi);
    }

public:
    Graph(int vertices) : v(vertices) {adj = new list<int>[vertices];}

    ~Graph() {
        delete adj;
    }

    void addEdge(int u, int w){
        adj[u].push_back(w);
    }

    list<int>& topologicalSort(){

        stack<int> Stack;

        vector<bool> visited(v, false);

        for(int i = 0; i < v; i++) 
            if(visited[i] == false) topologicalSortUtil(i, visited, Stack);

        list<int>* newList = new list<int>;

        while(Stack.empty() == false) {
            (*newList).push_back(Stack.top());
            Stack.pop();
        }

        return *newList;
    }
};

int main(){

    Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
  
    cout << "Following is a Topological Sort of the given graph \n"; 
    auto& x =  g.topologicalSort();

    copy(x.begin(), x.end(), ostream_iterator<int>(cout, " "));
}