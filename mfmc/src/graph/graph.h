#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <vector>

class Graph {
   private:
    unsigned int n;
    unsigned int num_vertex_weights;
    unsigned int num_edge_weights;
    // adj_list[from][to]
    std::vector<std::list<int>> adj_list;
    // v_weights[vertex][weight_index]
    std::vector<std::vector<int>> v_weights;
    // e_weights[from][to][weight_index]
    std::vector<std::list<std::vector<int>>> e_weights;

    // ~Graph();

   public:
    Graph();
    Graph(int n);
    Graph(int n, int n_v_weights, int n_e_weights);

    void add_edge(int u, int v);
    void add_edge(int u, int v, std::vector<int> &weights);

    void add_vertex();
    void add_vertex(std::vector<int> &weights);

    unsigned int size() const;
    unsigned int get_num_vertex_weights();
    unsigned int get_num_edge_weights();

    std::list<int> get_edges(int vertex);
    int get_vertex_weight(int vertex, int weight_index);
    std::list<std::vector<int>>::iterator get_edge_weights_begin(int vertex);
    std::list<std::vector<int>>::iterator get_edge_weights_end(int vertex);

    void set_vertex_weight(int vertex, int weight_index, int weight);

    std::list<int> path_to(int from, int to);
};

Graph read_graph_file(char *filename);
void print_graph(Graph &graph);

#endif
