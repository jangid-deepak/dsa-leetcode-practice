#include <iostream>
#include <vector>
#include <string>
#include <queue>


using namespace std;

class Graph {
    private:
        int V;
        vector<vector<int>> adj;

    public:
        Graph(int v) {
            V = v;
            adj.resize(V);
        }

        void addEdge(int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        void printGraph() {
            cout << "Printing graph: "<< endl;
            for(int i=0; i < V; i++) {
                cout << "i: " << i << " " << endl;
                for(int v: adj[i]) {
                    cout << v << " -> ";
                }
                cout << endl;
            }
            cout << endl;
        }
};

class Solution {
    public:
       int countCompleteComponents(int n, vector<vector<int>>& edges) {
            Graph g(n);
            for(vector<int> edge: edges) {
                g.addEdge(edge[0], edge[1]);
            }

            g.printGraph();

            return 0;
       }
};
int main() {
    Solution sol;
    
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {3, 4}};
    int ans = sol.countCompleteComponents(6, edges);
    cout << "ans: " << ans << endl;
    return 0;
}