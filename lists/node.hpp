template<typename KeyT>
struct Node {
	using pointer = Node*;

	KeyT data;
	pointer next;

	Node() : data{0}, next{nullptr} {};

	Node(KeyT data) : data{data}, next{nullptr} {};

	Node(KeyT data, pointer next) : data{data}, next{next} {};

	KeyT& operator*() {return data;}
};