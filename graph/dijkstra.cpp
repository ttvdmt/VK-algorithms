#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

template <class T>
inline void hash_combine(std::size_t& seed, T const& v)
{
	seed ^= std::hash<T>()(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

namespace std
{
	template<typename T>
	struct hash<vector<T>>
	{
		typedef vector<T> argument_type;
		typedef std::size_t result_type;
		result_type operator()(argument_type const& in) const
		{
			size_t size = in.size();
			size_t seed = 0;
			for (size_t i = 0; i < size; i++)
				hash_combine(seed, in[i]);
			return seed;
		}
	};
}

inline int vertexWithMinWeight(std::vector<std::vector<int>>& graph, std::unordered_map<std::vector<int>, bool>& visited, std::unordered_map<std::vector<int>, int>& dist)
{
	int index = 0;
	int dist_min = INT_MAX;
	for (int i = 0; i < graph.size(); i++) {
		if (dist[graph[i]] < dist_min && !visited[graph[i]]) {
			dist_min = dist[graph[i]];
			index = i;
		}
	}
	return index;
}

inline std::unordered_map<std::vector<int>, int> dijkstra(std::vector<std::vector<int>>& graph, int start)
{
	int INF = INT_MAX;
	bool false_flag = true;

	std::unordered_map<std::vector<int>, bool> visited;
	for (auto& vertex : graph) {
		visited[vertex] = false;
		false_flag = false;
	}

	std::unordered_map<std::vector<int>, int> dist;
	for (auto& vertex : graph)
		dist[vertex] = INF;

	dist[graph[start]] = 0;

	while (!false_flag) {
		auto u = vertexWithMinWeight(graph, visited, dist);
		for (int v = 0; v < graph[u].size(); v++) {
			if (graph[u][v] != 0 && !visited[graph[v]]) {
				dist[graph[v]] = std::min(dist[graph[v]], dist[graph[u]] + graph[u][v]);
			}
		}
		visited[graph[u]] = true;
		false_flag = true;
		for (auto& elem : visited) {
			if (!elem.second)
				false_flag = false;
		}
	}
	return dist;
}