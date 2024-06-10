#include <vector>
#include <unordered_map>
#include <iostream>

inline bool dfs(std::vector<std::vector<int>>& graph, int vertex, int parent, std::unordered_map<int, int>& visited)
{
	visited[vertex] = 0;
	for (auto elem : graph[vertex]) {
		if (elem != parent) {
			if (visited.find(vertex) != visited.end() || dfs(graph, elem, vertex, visited))
				return true;
		}
	}
	return false;
}

inline bool has_cycle(std::vector<std::vector<int>>& graph)
{
	std::unordered_map<int, int> visited;
	for (auto& v : graph) {
		for (auto vertex : v) {
			if (visited.find(vertex) == visited.end()) {
				if (dfs(graph, vertex, 0, visited))
					return true;
			}
		}
	}
	return false;
}