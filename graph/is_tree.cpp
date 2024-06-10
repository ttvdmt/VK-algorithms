#include <vector>
#include <iostream>
#include <unordered_map>

inline bool is_tree(std::vector<std::vector<int>>& graph, int start)
{
	if (graph.size() == 0 || graph.size() == 1)
		return true;

	std::unordered_map<int, int> visited;
	std::vector<int> queue = { start };
	std::unordered_map<int, int> parent;
	parent[start] = 0;

	while (queue.size() != 0) {
		int v = *(queue.end() - 1);
		queue.pop_back();
		visited[v] = 0;
		for (int neighbor = 0; neighbor < graph[v].size(); neighbor++) {
			if (graph[v][neighbor] != 0  && visited.find(neighbor) != visited.end()) {
				queue.push_back(neighbor);
				parent[neighbor] = v;
			}
			else {
				if (parent[v] != neighbor)
					return false;
			}
		}
	}
	return (visited.size() == graph.size());
}