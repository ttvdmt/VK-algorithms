#include <vector>
#include <unordered_map>

inline void dfs(std::vector<std::vector<int>>& graph, int v, std::unordered_map<int, bool>& visited, std::vector<int>& component)
{
	visited[v] = true;
	component.push_back(v);
	for (auto elem : graph[v]) {
		if (!visited[elem])
			dfs(graph, elem, visited, component);
	}
}

inline std::vector<std::vector<int>> find_connection_comp(std::vector<std::vector<int>>& graph)
{
	std::unordered_map<int, bool> visited;
	for (int i = 0; i < graph.size(); i++) {
		visited[i] = false;
	}
	std::vector<std::vector<int>> connected_comp;
	for (int i = 0; i < graph.size(); i++) {
		if (!visited[i]) {
			std::vector<int> component;
			dfs(graph, i, visited, component);
			connected_comp.push_back(component);
		}
	}
	return connected_comp;
}