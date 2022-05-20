#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>

#include "graph.h"

Graph read_graph(std::ifstream& file);
std::pair<int, int> get_num_weights(std::string& line);
void process_weights(std::ifstream& file, Graph& graph);
void process_vertex_weights(std::ifstream& file, Graph& graph,
                            int vertex_weight_index);
void process_edge_weights(std::ifstream& file, Graph& graph,
                          int edge_weight_index);

/**
 * Read a file and return a graph
 **/
Graph read_graph_file(char* filename) {
    Graph graph(0);

    std::ifstream file;
    file.open(filename);
    if (file.is_open()) {
        graph = read_graph(file);
        file.close();
    }

    return graph;
}

void print_graph(Graph& graph) {
    std::cout << "GRAPH V(" << graph.get_num_vertex_weights() << ") ";
    std::cout << "E(" << graph.get_num_edge_weights() << ")" << std::endl;
    for (unsigned int i = 0; i < graph.size(); i++) {
        for (auto const& i : graph.get_edges(i)) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "." << std::endl;

    for (unsigned int i = 0; i < graph.get_num_vertex_weights(); i++) {
        std::cout << std::endl << "VERTEX " << i << std::endl;
        for (unsigned int vertex = 0; vertex < graph.size(); vertex++) {
            std::cout << graph.get_vertex_weight(vertex, i) << " ";
        }
        std::cout << std::endl << "." << std::endl;
    }

    for (unsigned int i = 0; i < graph.get_num_edge_weights(); i++) {
        std::cout << std::endl << "EDGE " << i << std::endl;
        for (unsigned int vertex = 0; vertex < graph.size(); vertex++) {
            auto end = graph.get_edge_weights_end(vertex);
            for (auto weight = graph.get_edge_weights_begin(vertex);
                 weight != end; weight++) {
                std::cout << (*weight)[i] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "." << std::endl;
    }
}

Graph read_graph(std::ifstream& file) {
    std::string line;
    std::getline(file, line);
    if (line.find("GRAPH") == std::string::npos) {
        return Graph(0);
    }

    std::pair<int, int> num_weights = get_num_weights(line);

    Graph graph(0, num_weights.first, num_weights.second);
    int vertex = 0;

    while (std::getline(file, line)) {
        if (line == ".") break;
        graph.add_vertex();
        std::istringstream iss(line);
        std::string num;
        while (std::getline(iss, num, ' ')) {
            graph.add_edge(vertex, std::stoi(num));
        }
        vertex++;
    }

    process_weights(file, graph);

    return graph;
}

void process_weights(std::ifstream& file, Graph& graph) {
    std::string line;
    int vertex_weight_index = 0;
    int edge_weight_index = 0;
    while (std::getline(file, line)) {
        if (line.find("VERTEX") != std::string::npos) {
            process_vertex_weights(file, graph, vertex_weight_index);
            vertex_weight_index++;
        } else if (line.find("EDGE") != std::string::npos) {
            process_edge_weights(file, graph, edge_weight_index);
            edge_weight_index++;
        }
    }
}

void process_vertex_weights(std::ifstream& file, Graph& graph,
                            int vertex_weight_index) {
    std::string line;
    std::getline(file, line);
    std::istringstream iss(line);
    std::string num;
    int vertex = 0;
    while (std::getline(iss, num, ' ')) {
        graph.set_vertex_weight(vertex, vertex_weight_index, std::stoi(num));
        vertex++;
    }
}

void process_edge_weights(std::ifstream& file, Graph& graph,
                          int edge_weight_index) {
    std::string line;
    int vertex = 0;
    while (std::getline(file, line)) {
        if (line == ".") break;
        std::istringstream iss(line);
        std::string num;
        auto end = graph.get_edge_weights_end(vertex);
        for (auto weights = graph.get_edge_weights_begin(vertex);
             weights != end; weights++) {
            std::getline(iss, num, ' ');
            (*weights)[edge_weight_index] = std::stoi(num);
        }
        vertex++;
    }
}

std::pair<int, int> get_num_weights(std::string& line) {
    std::pair<int, int> p(0, 0);
    std::istringstream iss(line);
    std::string current;
    std::getline(iss, current, ' ');  // GRAPH
    std::getline(iss, current, ' ');  // V
    if (current.size() >= 4)
        p.first = std::stoi(current.substr(2, current.size() - 3));
    std::getline(iss, current, ' ');  // E
    if (current.size() >= 4)
        p.second = std::stoi(current.substr(2, current.size() - 3));
    return p;
}
