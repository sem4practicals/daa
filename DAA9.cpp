#include <iostream>
#include <climits>
using namespace std;
int minKey(int* key, bool* mstSet, int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }return min_index;
}
void primMST(int** graph, int V) {
	int sum=0;
    int* parent = new int[V];  
    int* key = new int[V];     
    bool* mstSet = new bool[V];
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;  
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << endl;
        sum+=graph[i][parent[i]];
    }
    delete[] parent;
    delete[] key;
    delete[] mstSet;
    cout<<"total weight: "<<sum;
}
int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    int** graph = new int*[V];
    for (int i = 0; i < V; i++) {
        graph[i] = new int[V]();  
    }
    cout << "Enter the number of edges: ";
    cin >> E;
    cout << "Enter the edges (u, v, weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u][v] = weight;
        graph[v][u] = weight;
    }
    primMST(graph, V);
}
