#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

/**
 * Basic Functions
 *  1.Constructor
 *  2.AddEdge
 *  3.RemoveEdge
 *  4.PrintGraph
 */

class Graph {
    private:
        int V; // Number of vertices
        vector<vector<int>> adj; // Adjacency list
    public:
        Graph(int vertices) {
            V = vertices;
            adj.resize(V);
        }

        void addEdge(int u, int v) {
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        void removeEdge(int u, int v) {
            // if (u >= 0 && u < adj.size() && v >= 0 && v < adj.size()) {
                adj[u].erase(remove(adj[u].begin(), adj[u].end(), v), adj[u].end());
                // adj[v].erase(remove(adj[v].begin(), adj[v].end(), u), adj[v].end());
            // }
        }
        void printGraph() {
            for(int i=0;i<V; i++) {
                cout << i << "-> ";
                for(int v: adj[i])
                    cout << v << " ";

                cout << endl;
            }
            
        }

        void breadthFirstSearch(int start) {
            vector<bool> visited(adj.size(), false);
            queue<int> q;
            visited[start] = true;
            q.push(start);
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                cout << node << " ";

                for(int n: adj[node]) {
                    if (!visited[n]) {
                        visited[n] = true;
                        q.push(n);
                    }
                }
            }
            cout << endl;
        }

        void DeepthFirstSearch(int start) {
            vector<bool> visited(adj.size(), false);
            DfsUtil(start, visited);
            cout << endl;
        }

        void DfsUtil(int node, vector<bool>& visited) {
            visited[node] = true;
            cout << node << " ";
            for (int n: adj[node]) {
                if (!visited[n]) {
                    DfsUtil(n, visited);
                }
            }
        }


        void kahnTopologicalSort() {
            vector<int> inDegree(V, 0);
            
            // Step 1: Compute In-Degree for all nodes
            for (int u = 0; u < V; u++) {
                for (int v : adj[u]) {
                    inDegree[v]++;
                }
            }
    
            // Step 2: Push nodes with in-degree = 0 into queue
            queue<int> q;
            for (int i = 0; i < V; i++) {
                if (inDegree[i] == 0) {
                    q.push(i);
                }
            }
    
            vector<int> topoOrder; // Stores topological ordering
    
            // Step 3: BFS Process
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                topoOrder.push_back(node);
    
                for (int neighbor : adj[node]) {
                    inDegree[neighbor]--; // Reduce in-degree
                    if (inDegree[neighbor] == 0) {
                        q.push(neighbor);
                    }
                }
            }
    
            // Step 4: Check for Cycle
            if (topoOrder.size() != V) {
                cout << "Cycle detected! No Topological Order possible." << endl;
                return;
            }
    
            // Step 5: Print Topological Order
            cout << "Topological Sort: ";
            for (int node : topoOrder) {
                cout << node << " ";
            }
            cout << endl;
        }
};


int main() {
    Graph g(6);
    g.addEdge(5, 0);
    g.addEdge(5, 2);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    // graph.addEdge(0, 1);
    // graph.addEdge(0, 3);
    // graph.addEdge(1, 2);
    // graph.addEdge(2, 3);    
    g.printGraph();
    cout << "BFS Traversal: " << endl;
    g.breadthFirstSearch(2);
    cout << "DFS Traversal: " << endl;
    g.DeepthFirstSearch(2);
    g.kahnTopologicalSort();
    return 0;
}