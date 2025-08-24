#include <iostream>
#include <vector>
using namespace std;

int main() {
    int V; // number of vertices
    cout << "Enter number of vertices: ";
    cin >> V;

    // Create VxV matrix initialized to 0
    vector<vector<int> > adjMatrix(V, vector<int>(V, 0));

    int E; // number of edges
    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges (from to):" << endl;
    for (int i = 0; i < E; i++) {
        int from, to;
        cin >> from >> to;
        adjMatrix[from][to] = 1; // directed edge
    }

    // Display matrix
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            cout << adjMatrix[i][j] << " ";
        cout << endl;
    }
    return 0;
}
