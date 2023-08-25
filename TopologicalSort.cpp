#include<unordered_map>
#include<stack>
#include<list>

void toposort(int node, vector<bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj) {
    visited[node] = true;
    for (auto neighbour : adj[node]) {
        if (!visited[neighbour])
            toposort(neighbour, visited, s, adj);
    }
    // Push the node onto the stack after visiting all its neighbors
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    // Create adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    // Call the DFS topological sort util function for all components
    vector<bool> visited(v, false);  // Initialize all nodes as not visited
    stack<int> s;
    for (int i = 0; i < v; i++) {
        if (!visited[i])
            toposort(i, visited, s, adj);
    }

    vector<int> ans;
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

//TC=O(N+E), SC=O(N)
