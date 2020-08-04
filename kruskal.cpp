#include<bits/stdc++.h>
using namespace std;

class DisjointSets 
{ 
    vector<int> *parent, *rnk; 
    int n;

public:
  
    // Constructor. 
    DisjointSets(int _n) : n(_n)
    {
		parent = new vector<int>(_n + 1);
		rnk = new vector<int>(_n + 1);
		iota((*parent).begin(), (*parent).end(), 0);
    }

    ~DisjointSets() {delete parent; delete rnk;}
  
    // Find the parent of a node 'u' 
    // Path Compression 
    int find(int u) 
    { 
        /* Make the parent of the nodes in the path 
           from u--> parent[u] point to parent[u] */
        if (u != (*parent)[u]) (*parent)[u] = find((*parent)[u]); 
        return (*parent)[u]; 
    } 
  
    // Union by rank 
    void merge(int x, int y) 
    { 
        x = find(x), y = find(y); 
  
        /* Make tree with smaller height 
           a subtree of the other tree  */
        if ((*rnk)[x] > (*rnk)[y]) (*parent)[y] = x; 
        else (*parent)[x] = y; 
  
        (*rnk)[y] += ((*rnk)[x] == (*rnk)[y]); 
    } 
}; 

class edge{
public:
    int u, v, w, indx;
    edge(int u, int v, int w, int indx):  u(u), v(v), w(w), indx(indx) {}
};

friend bool operator<(const edge& a, const edge& b) {
    return a.w < b.w;
}

const int N = 1e5 + 1;

edge edges[N];




int32_t main(){

}

