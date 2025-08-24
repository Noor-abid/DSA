#include <iostream>
#include <vector>
using namespace std;

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int> > adjMatrix(V, vector<int>(V, 0)); // VxV matrix filled with 0

    int E;
    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // remove if directed
    }

    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            cout << adjMatrix[i][j] << " ";
        cout << endl;
    }
}
