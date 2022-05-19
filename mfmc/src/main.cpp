#include <iostream>
#include <list>

#include "graph/graph.h"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " [filename]" << std::endl;
        return 1;
    }

    Graph g = read_graph_file(argv[1]);
    print_graph(g);

    std::list<int> l = g.path_to(0, 5);
    for (auto const& i : l) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
