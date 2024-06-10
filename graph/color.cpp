#include <vector>
#include <unordered_map>

inline void dfs(std::vector<std::vector<int>>& graph, int v, std::unordered_map<int, int>& visited, int color)
{
	visited[v] = color;
	for (auto elem : graph[v]) {
		if (!visited[elem])
			dfs(graph, elem, visited, color);
	}
}

inline std::unordered_map<int, int> find_connection_comp(std::vector<std::vector<int>>& graph)
{
	std::unordered_map<int, int> visited;
	for (int i = 0; i < graph.size(); i++) {
		visited[i] = 0;
	}
	int color = 0;
	for (int node = 0; node < graph.size(); node++) {
		if (visited[node] == 0) {
			color++;
			dfs(graph, node, visited, color);
		}
	}
	return visited;
}
