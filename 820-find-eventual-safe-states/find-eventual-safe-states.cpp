class Solution {
public:

    bool dfs(int node, vector<vector<int>>& graph,
             vector<int>& visited,
             vector<int>& path,
             vector<int>& safe) {

        visited[node] = 1;
        path[node] = 1;

        for (int neighbor : graph[node]) {

            // If neighbor is not visited
            if (!visited[neighbor]) {
                if (!dfs(neighbor, graph, visited, path, safe)) {
                    return false;
                }
            }

            // Neighbor is in current DFS path -> cycle
            else if (path[neighbor]) {
                return false;
            }
        }

        path[node] = 0;
        safe[node] = 1;

        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int V = graph.size();

        vector<int> visited(V, 0);
        vector<int> path(V, 0);
        vector<int> safe(V, 0);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, graph, visited, path, safe);
            }
        }

        vector<int> ans;

        for (int i = 0; i < V; i++) {
            if (safe[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};