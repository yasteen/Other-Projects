
#include "graph.h"

Graph::Graph() : Graph(0) {}

Graph::Graph(int n) : Graph(n, 0, 0) {}

Graph::Graph(int n, int num_vertex_weights, int num_edge_weights)
    : n(n),
      num_vertex_weights(num_vertex_weights),
      num_edge_weights(num_edge_weights) {
    adj_list.resize(n);
    v_weights.resize(n);
    e_weights.resize(n);
}

// Graph::~Graph() {
//     for (auto const& edges : this->adj_list)
//         delete edges;
// }

void Graph::add_edge(int u, int v) {
    std::vector<int> vec;
    this->add_edge(u, v, vec);
}

void Graph::add_edge(int u, int v, std::vector<int>& weights) {
    adj_list[u].push_back(v);

    if (weights.size() != num_edge_weights) {
        weights.resize(num_edge_weights);
    }

    e_weights[u].push_back(weights);
}

void Graph::add_vertex() {
    std::vector<int> v;
    this->add_vertex(v);
}

void Graph::add_vertex(std::vector<int>& weights) {
    std::list<int> l;
    adj_list.push_back(l);
    n++;

    if (weights.size() != num_vertex_weights) {
        weights.resize(num_vertex_weights);
    }

    v_weights.push_back(weights);

    std::list<std::vector<int>> e_lst;
    e_weights.push_back(e_lst);
}

unsigned int Graph::size() const { return n; }
unsigned int Graph::get_num_vertex_weights() { return num_vertex_weights; }
unsigned int Graph::get_num_edge_weights() { return num_edge_weights; }

std::list<int> Graph::get_edges(int vertex) { return adj_list[vertex]; }
int Graph::get_vertex_weight(int vertex, int weight_index) {
    return v_weights[vertex][weight_index];
}
std::list<std::vector<int>>::iterator Graph::get_edge_weights_begin(
    int vertex) {
    return e_weights[vertex].begin();
}
std::list<std::vector<int>>::iterator Graph::get_edge_weights_end(int vertex) {
    return e_weights[vertex].end();
}

void Graph::set_vertex_weight(int vertex, int weight_index, int weight) {
    v_weights[vertex][weight_index] = weight;
}

std::list<int> Graph::path_to(int from, int to) {
    std::list<int> queue;

    std::vector<int> prev;
    prev.resize(n, -1);

    queue.push_back(from);
    prev[from] = from;

    int current;
    while (!queue.empty()) {
        current = queue.front();
        queue.pop_front();

        for (auto adjacent : adj_list[current]) {
            if (prev[adjacent] == -1) {
                prev[adjacent] = current;
                queue.push_back(adjacent);
            }
        }
    }

    if (prev[to] == -1) return queue;
    current = to;
    while (current != from) {
        queue.push_front(current);
        current = prev[current];
    }
    queue.push_front(from);
    return queue;
}
